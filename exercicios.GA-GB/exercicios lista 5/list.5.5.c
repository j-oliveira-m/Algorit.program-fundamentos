/*5. Uma empresa está monitorando o consumo de água em uma residência ao longo de um mês (30 
dias). Para agilizar o preenchimento dos dados, faça o sorteio de valores entre 100 e 500 litros por 
dia. Escreva um programa que: 
a. Sorteie e armazene o consumo diário de água (em litros) em um vetor. 
b. Calcule o consumo total do mês. 
c. Calcule a média de consumo diário.  
d. Imprima o dia em que houve o maior consumo e o menor consumo de água. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){ 

        srand(time(NULL)) ;

        int numero[30] ;
        int consumo = 0;
        int i;

        for(i = 0; i < 30; i++){
            numero[i] = 100 + rand() % 401;
                consumo+= numero[i] ;

            printf("valores vetor %d\n", numero[i]);
        }
            int media = consumo / 30 ;

            int menorConsumo = numero[0];
            int maiorConsumo = numero[0];
            int indiceMenor = 0 ;
            int indiceMaior = 0;

        for(int j = 0; j < 30; j++){
            if(numero[j] > maiorConsumo){
                maiorConsumo = numero[j] ;
                  indiceMaior = j ;

            } else if(numero[j] < menorConsumo){
                menorConsumo = numero[j] ;
                    indiceMenor = j;
            }
        }

        printf("consumo total do Mes: %d\n", consumo);
        printf("media de consumo diario: %d\n", media);
        printf("dia de menor consumo: %d\n e dia de maior consumo: %d\n", indiceMenor +1, indiceMaior +1);
        


    return 0;
}