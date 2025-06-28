
/*1- Criar um vetor de 10 números v e inicialize-o sorteando valores de 10 a 90 para cada elemento. 
Depois disso, implemente algoritmos para: 

a. Imprimir o vetor - feito*
b. Verificar se existe o valor 50 neste vetor (apenas dizer se encontrou ou não) - feito*
c. Verificar o número de ocorrências do valor 50 neste vetor. - feito*
d. Calcular a média dos valores do vetor - feito*
e. Encontrar o maior e o menor valor dos elementos do vetor. - feito*
f. Imprimir a soma e o produto acumulado dos valores dos elementos do vetorb - feito*
g. Imprimir o vetor em ordem inversa - feito#
h. Copiar os elementos em ordem inversa para outro vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int numeros[10];
    int inverso[10];
    int vPares[10], vImpares[10];
    int qtdPares = 0, qtdImpares = 0;

    int sorteando;
    int min = 10, max = 90;
    int achou = 0, contador = 0;
    float soma = 0, media;
    int produto = 1;

    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    
    for (int i = 0; i < tamanho; i++) {
        sorteando = min + rand() % (max - min + 1);
        numeros[i] = sorteando;
    }

    int maior = numeros[0];
    int menor = numeros[0];

    
    for (int i = 0; i < tamanho; i++) {
        printf("vetor[%d]: %d\n", i + 1, numeros[i]);

        soma += numeros[i];
        produto *= numeros[i];

        if (numeros[i] > maior) maior = numeros[i];
        if (numeros[i] < menor) menor = numeros[i];

        if (numeros[i] == 50) {
            achou = 1;
            contador++;
        }

        
        if (numeros[i] % 2 == 0) {
            vPares[qtdPares++] = numeros[i];
        } else {
            vImpares[qtdImpares++] = numeros[i];
        }
    }

    
    if (achou) {
        printf("\nExiste o número 50.\n");
    } else {
        printf("\nNão existe o número 50.\n");
    }

        printf("O número 50 apareceu %d vez(es).\n", contador);
        media = soma / tamanho;
        printf("A média dos valores: %.2f\n", media);
        printf("Maior valor: %d\n", maior);
        printf("Menor valor: %d\n", menor);
        printf("Soma: %.2f\n", soma);
        printf("Produto acumulado: %d\n", produto);

    
    for (int i = 0; i < tamanho; i++) {
        inverso[i] = numeros[tamanho - 1 - i];
    }

        printf("\nVetor em ordem inversa (copiado):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("inverso[%d]: %d\n", i + 1, inverso[i]);
    }

    
        printf("\nElementos pares (%d):\n", qtdPares);
    for (int i = 0; i < qtdPares; i++) {
        printf("vPares[%d]: %d\n", i + 1, vPares[i]);
    }

        printf("\nElementos ímpares (%d):\n", qtdImpares);
    for (int i = 0; i < qtdImpares; i++) {
        printf("vImpares[%d]: %d\n", i + 1, vImpares[i]);
    }

    return 0;
}

