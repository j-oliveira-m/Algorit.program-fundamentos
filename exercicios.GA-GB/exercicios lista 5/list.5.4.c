/*4. Uma pessoa está monitorando quantos passos ela dá por dia em uma semana. Escreva um 
programa que: 
a. Leia e armazene o número de passos dados em cada um dos 7 dias da semana. 
b. Calcule o total de passos dados na semana. 
c. Calcule a média diária de passos. 
d. Verifique se a pessoa conseguiu atingir a meta de 10.000 passos em algum dos dias. Se sim, 
informe quais dias a meta foi alcançada.   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int numeros[7];
    int totalPassos = 0;
    int mediaDiaria ;
    

        for(int i = 0; i < 7; i++){

            printf("digite o numero de passos dados por dia: dia %d\n", i + 1);
                scanf("%d", &numeros[i]);
                totalPassos += numeros[i] ;     //total de passos
            
        }

        mediaDiaria = totalPassos / 7 ;         //media de passos

        printf("total de passos na semana: %d\n", totalPassos);
        printf("media diaria de passos: %d\n", mediaDiaria);

        for (int i = 0; i < 7; i++)
        {
            if(numeros[i] >= 10000){
                printf("\ndia %d: passos %d\n:", i + 1, numeros[i]);
            }
        }
            return 0;

}