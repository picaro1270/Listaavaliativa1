#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>

// Função para buscar a página da Wikipedia
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Função para verificar se ocorreu um evento em um ano
bool verificaEventoNoAno(const char *url, int ano, const char *evento) {
    CURL *curl;
    CURLcode res;
    char filename[50];
    snprintf(filename, sizeof(filename), "temp_%d.html", ano);
    FILE *fp = fopen(filename, "wb");

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
        fclose(fp);
        if (res != CURLE_OK) {
            return false;
        }
    } else {
        fclose(fp);
        return false;
    }

    fp = fopen(filename, "r");
    if (!fp) {
        return false;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, evento)) {
            fclose(fp);
            remove(filename);
            return true;
        }
    }

    fclose(fp);
    remove(filename);
    return false;
}

int main() {
    int ano;
    printf("Digite um ano (1800 <= ano <= 2022): ");
    scanf("%d", &ano);

    if (ano < 1800 || ano > 2022) {
        printf("Ano fora do intervalo permitido.\n");
        return 1;
    }

    bool ocorreuOlimpiadas = verificaEventoNoAno("https://pt.wikipedia.org/wiki/Jogos_Ol%C3%ADmpicos_de_Ver%C3%A3o", ano, "Lista dos Jogos Olímpicos de Verão");
    bool ocorreuCopaDoMundo = verificaEventoNoAno("https://pt.wikipedia.org/wiki/Copa_do_Mundo_FIFA", ano, "Por edições");

    if (!ocorreuOlimpiadas && !ocorreuCopaDoMundo) {
        printf("Não houve Jogos Olímpicos de Verão ou Copa do Mundo no ano de %d.\n", ano);
    } else {
        if (ocorreuOlimpiadas) {
            printf("Os Jogos Olímpicos de Verão ocorreram no ano de %d.\n", ano);
        }
        if (ocorreuCopaDoMundo) {
            printf("A Copa do Mundo de Futebol ocorreu no ano de %d.\n", ano);
        }
    }

    return 0;
}
