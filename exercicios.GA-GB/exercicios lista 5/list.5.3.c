/*3. Faça um programa para testar se um dado é viciado. Faça o lançamento N vezes (N é um número 
lido pelo usuário, pode ser um  número bem grande), armazene cada valor que for sorteado em um 
array com 6 posições e ao final imprima o percentual do resultado de cada face.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
        srand(time(NULL)) ;

    
    int lancamento;
    int contador[6] = {0} ;


        printf("digite a quantidade de lancamentos a ser feito: " );
            scanf("%d", &lancamento);

        for(int i = 0; i < lancamento; i++){

            int resultado = 1 + rand() % 6 ;
                contador[resultado -1]++ ;

            
        }
        printf("percentual de aparicoes de cada face\n");

        for(int i = 0; i < 6 ; i++){
            float percentual = contador[i] * 100.0 / lancamento;

            printf("Face %d: %.2f%%\n", i + 1, percentual);
        }
        
    return 0;
}