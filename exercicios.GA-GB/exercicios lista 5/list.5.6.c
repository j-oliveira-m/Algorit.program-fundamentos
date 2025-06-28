/*6. Em um jogo com 5 rodadas e 4 jogadores, cada jogador começa com 0 pontos. Escreva um 
programa que: 
a. Crie um vetor de 4 elementos, onde cada posição do vetor representa a pontuação 
acumulada de um jogador. 
b. A cada rodada, sorteie a pontuação para cada jogador (valores entre 0 e 100). 
c. Atualize o vetor de pontuação acumulada com a soma da pontuação de cada rodada. 
d. Ao final de cada rodada, verifique se algum jogador fez mais de 80 pontos e exiba uma 
mensagem de "Rodada de Destaque" para esse jogador. 
e. Ao final das 5 rodadas, exiba a pontuação total de cada jogador. 
f. 
Informe qual jogador venceu, ou se houve empate (o jogador com a maior pontuação).*/
  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));

    
    int pontos[4] = {0, 0, 0, 0};

    
    for (int rodada = 1; rodada <= 5; rodada++) {
        printf("\nRodada %d:\n", rodada);

        
        for (int jogador = 0; jogador < 4; jogador++) {
            
            int pontosDaRodada = rand() % 101;

            
            pontos[jogador] = pontos[jogador] + pontosDaRodada;

            
            printf("Jogador %d fez %d pontos\n", jogador + 1, pontosDaRodada);

            
            if (pontosDaRodada > 80) {
                printf(" -> Jogador %d teve uma RODADA DE DESTAQUE!\n", jogador + 1);
            }
        }
    }

    
    printf("\nPontuação Final:\n");
    for (int jogador = 0; jogador < 4; jogador++) {
        printf("Jogador %d: %d pontos\n", jogador + 1, pontos[jogador]);
    }

    
    int maiorPontuacao = pontos[0];
    int vencedor = 0;
    int empate = 0;

    for (int jogador = 1; jogador < 4; jogador++) {
        if (pontos[jogador] > maiorPontuacao) {
            maiorPontuacao = pontos[jogador];
            vencedor = jogador;
            empate = 0;  
        } else if (pontos[jogador] == maiorPontuacao) {
            empate = 1;  
        }
    }

    
    if (empate == 1) {
        printf("\nHouve EMPATE na maior pontuação!\n");
    } else {
        printf("\nJogador %d venceu com %d pontos!\n", vencedor + 1, maiorPontuacao);
    }

    return 0;
}