#include <stdio.h>

int main() {
    long long int n;
    printf("Digite um número inteiro positivo N (0 <= N <= 1000000000): ");
    scanf("%lld", &n);

    if (n < 0 || n > 1000000000) {
        printf("Número fora do intervalo permitido.\n");
        return 1;
    }

    // Verificar se o número é ímpar ou par
    if (n % 2 == 0) {
        printf("O número inserido é par.\n");
    } else {
        printf("O número inserido é ímpar.\n");
    }

    // Calcular a soma dos dígitos
    long long int soma = 0;
    long long int numero = n;
    
    while (numero != 0) {
        soma += numero % 10;
        numero /= 10;
    }

    printf("A soma dos algarismos do número é: %lld\n", soma);

    return 0;
}
