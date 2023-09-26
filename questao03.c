#include <stdio.h>

int main() {
    int senha_cadastrada;
    int senha_digitada;

    printf("Digite a senha numérica de 4 dígitos: ");
    scanf("%d", &senha_cadastrada);

    printf("Senha cadastrada: %d\n", senha_cadastrada);

    while (1) {
        printf("Digite a senha para validar: ");
        scanf("%d", &senha_digitada);

        if (senha_digitada == senha_cadastrada) {
            printf("Senha válida!\n");
            break;
        } else {
            printf("Senha inválida!\n");
        }
    }

    return 0;
}