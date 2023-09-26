#include <stdio.h>


int ocorreramOlimpiadas(int ano) {
    
    int olimpiadas[] = { 1896, 1900, 1904, 1908, 1912, 1920, 1924, 1928, 1932, 1936, 1948, 1952, 1956, 1960, 1964, 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020, 2024 };
    int numOlimpiadas = sizeof(olimpiadas) / sizeof(olimpiadas[0]);

    for (int i = 0; i < numOlimpiadas; i++) {
        if (ano == olimpiadas[i]) {
            return 1; 
        }
    }

    return 0; 
}


int ocorreuCopaDoMundo(int ano) {
    int copaDoMundo[] = { 1930, 1934, 1938, 1950, 1954, 1958, 1962, 1966, 1970, 1974, 1978, 1982, 1986, 1990, 1994, 1998, 2002, 2006, 2010, 2014, 2018, 2022 };
    int numCopas = sizeof(copaDoMundo) / sizeof(copaDoMundo[0]);

    for (int i = 0; i < numCopas; i++) {
        if (ano == copaDoMundo[i]) {
            return 1; 
        }
    }

    return 0; 
}

int main() {
    int ano;

    printf("Digite o ano que você deseja verificar: ");
    scanf("%d", &ano);

    if (ocorreramOlimpiadas(ano)) {
         printf("Jogos Olímpicos de Verão ocorreram em %d.\n", ano);
    } else {
        printf("Jogos Olímpicos de Verão não ocorreram em %d.\n", ano);
    }

    if (ocorreuCopaDoMundo(ano)) {
        printf("A Copa do Mundo de Futebol ocorreu no ano de %d.\n", ano);
    } else {
        printf("Não houve Jogos Olímpicos de Verão ou Copa do Mundo no ano de %d.\n", ano);
    }

    return 0;
}
