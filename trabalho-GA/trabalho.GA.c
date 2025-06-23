/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h>


int main() {
    
    int opcao, Infectados, dias, populacaoTotal, porcentagempop_vacinada ; // declarando parte das váriaveis que usaremos para armazenar os dados usados no programa//
    
    float taxa_contagio, efetividade ;
    int vacinados_infectados = 0;
    
    
        printf("\nMENU INICIAL\n");  // menu de opções para questinar o usuário se quer prosseguir ou encerrar o programa//
        printf("escolha uma opção:\n" );
        printf("opção 1: iniciar uma nova simulação.\n" );
        printf("opção 2: sair do programa \n" );
            scanf("%d", &opcao);
         
    if(opcao == 1){
        
        printf("\nnúmero da população total: \n" );
            scanf("%d", &populacaoTotal);
    
        printf("\nnúmero de pessoas inicialmente infectadas: \n" );
            scanf("%d", &Infectados);
        
        printf("\ntaxa de contagio :  \n");
            scanf("%f", &taxa_contagio);
            
        printf("\nporcentagem da população vacinada : \n" );
            scanf("%d", &porcentagempop_vacinada);
          
        printf("\ndigite a porcentagem da efetividade da vacina: \n" );
            scanf("%f", &efetividade);
            
        printf("\npor fim, digite o número de dias da simulação: \n" );
            scanf("%d", &dias);                                    // coletando os dados que vamos armazenar nas váriavies e utilizar no deccorer do programa//
    
    } else if(opcao == 2){
    
        printf("programa encerrado.\n" ); 
        
    } 
    
        srand(time(NULL)) ;      // sorteio de possíveis eventos que possam alterar a taxa de contagio //
        
            int vacinados = populacaoTotal * (porcentagempop_vacinada / 100.0);
        
            printf("\nPopulação: %d\n", populacaoTotal);
            printf("Infectados iniciais: %d\n", Infectados);
            printf("Taxa de contágio: %.0f%%\n", taxa_contagio);
            printf("População vacinada: %f\n", populacaoTotal * (porcentagempop_vacinada / 100.0));
            printf("Efetividade da vacina: %.0f%%\n", efetividade);
            printf("Dias simulados: %d\n", dias);
        
        for (int dia = 1; dia <= dias; dia++) {         //contar os dias//
     
        int saudaveis_totais = populacaoTotal - Infectados;

        float vacinadosSaudaveis = (porcentagempop_vacinada / 100.0) * saudaveis_totais; //calculos utilizados para descobrir as pessoas saudaveis e vacinadas, e as vacinadas que tiveram efetividade a vacina//
        float naoVacinadossau = saudaveis_totais - vacinadosSaudaveis;
        float suscetiveis = naoVacinadossau + vacinadosSaudaveis * (1 - efetividade / 100.0); 
        
            int novos_infectados = Infectados * (taxa_contagio / 100);
            int novos_vacinados_infectados = vacinadosSaudaveis * (1 - efetividade / 100.0);
            
                if (novos_vacinados_infectados > novos_infectados) {
                    
                    novos_vacinados_infectados = novos_infectados;
}

                    vacinados_infectados += novos_vacinados_infectados;

                int sorteio_prob = rand() % 100 + 1;
                
                if(sorteio_prob < 5 ){
                    taxa_contagio += taxa_contagio * 0.50; // mutação mais contagiosa 5% = 50% //
                    
                } else if(sorteio_prob < 10){
                    taxa_contagio -= taxa_contagio * 0.30;  // midia gera alerta 5% = -30%  //
                    
                } else if(sorteio_prob < 20){
                    taxa_contagio -= taxa_contagio * 0.20; //isolamento voluntário 10% = -20%//
                
                } else if(sorteio_prob < 35){
                    taxa_contagio += taxa_contagio * 0.25; //aglomeração 15% = 25% //
                    
                } 
                
                
                if(suscetiveis <= 0){
                    printf("todos os suscetiveis foram infectados. \n");
                        break;
                        
                } else if (novos_infectados > suscetiveis){ 
                    novos_infectados = suscetiveis;
                    
                }
                
                Infectados += novos_infectados;
                
                printf("\nDia %d: %d infectados (+%d)", dia, Infectados, novos_infectados);
                
                if (sorteio_prob < 5) {
                    printf(" (evento: Mutação mais contagiosa!)");
                } else if (sorteio_prob < 10) {
                    printf(" (evento: Mídia gera alerta!)");
                } else if (sorteio_prob < 20) {
                    printf(" (evento: Isolamento voluntário!)");
                } else if (sorteio_prob < 35) {
                    printf(" (evento: Aglomeração!)");
        }

                    printf("\n");
    }   
                   
                int saudaveis_fim = populacaoTotal - Infectados ;
                
                    printf("\nTotal infectados: %d", Infectados);
                    printf("\nPopulação vacinada: %d", vacinados);
                    printf("\nVacinados infectados: %d", vacinados_infectados);
                    printf("\nPopulação saudável:   %d", saudaveis_fim);
                

         
    return 0;
}