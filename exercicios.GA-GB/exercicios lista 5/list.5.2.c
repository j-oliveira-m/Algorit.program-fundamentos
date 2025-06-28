/*2- Faça um programa que leia 5 valores para dentro de um vetor e imprima o resultado de cada
valor multiplicado pela sua posição no vetor. Por exemplo: 1, 2, 3, 4 e 5 imprimirá na tela 0, 2, 6,
12 e 20.*/ 
# include <stdio.h>

int main()
{
    int numeros[5];
    int resultado;

        for(int i = 0; i < 5; i++){

                printf("digite 5 numeros: numero %d\n", i+1);
                scanf("%d", &numeros[i]);

        }
        for(int i = 0; i < 5; i++ ){
            printf("numero da posicao %d\n: %d\n", i+1, numeros[i]);
        }

        for(int i = 0; i < 5; i++){
            resultado = numeros[i] * i;

            printf("Posicao %d (indice %d) × %d = %d\n", i + 1, i, numeros[i], resultado);
        }


    return 0;
}