#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


    struct personagem{         //struct para criação do perfil de cada personagem.

        int classe;
        int vida; 
        int ataque;
        int defesa;
};

    int equipeMorta(struct personagem time[]) { //para verificar se todos personagens de uma equipe morreram
        int i;

        for (i = 0; i < 5; i++) {
            if (time[i].vida > 0) {
                return 0;  
        }
    }
    return 1;  
}

    int escolherAtacante(struct personagem time[]){     //escolhe o personagem que será o atacante(que ainda esteja vivo)
    
        for(int i = 0; i < 5; i++){
            if(time[i].vida > 0){

        return i ;
       }
       
    }
        return -1 ;  
}

    int escolherDefensor(struct personagem time[]){  //escolhe o personagem que irá defender o ataque(que ainda esteja vivio)

        int posicao;

        do {
            posicao = rand() % 5;
        } while(time[posicao].vida <= 0);

        return posicao;  
 }


    void mostrarClasse(int c) {     //mostra a qual classe o personagem pertence com base no número

        if (c == 0) printf("guerreiro");
            else if (c == 1) printf("mago");
        else if (c == 2) printf("cacador");
            else if (c == 3) printf("paladino");
        else if (c == 4) printf("barbaro");
}

    void realizarAtaque(struct personagem timeAtacante[], int atacante, //função para realizar o ataque entre dois personagens
                struct personagem timeDefensor[], int defensor) {

        int erro = (rand() % 100) < 20;     // 20% de chance de erro
            if (timeAtacante[atacante].classe == 4) {
        erro = 0;       // bárbaro não erra
    }

        printf("Atacante: ");        //mostra a forma do ataque
            mostrarClasse(timeAtacante[atacante].classe);
        printf(" (Vida: %d) ataca Defensor: ", timeAtacante[atacante].vida);
            mostrarClasse(timeDefensor[defensor].classe);
        printf(" (Vida: %d)\n", timeDefensor[defensor].vida);

        if (erro) {          //encerra o ataque se errou
            printf(" Ataque errou!\n\n");
        return;
    }

        int falhaDefesa = (rand() % 100) < 20;      // porcentagem que pode falhar a defesa
            int defesa_final;

            if (falhaDefesa) {
                defesa_final = 0;
            } else {

        defesa_final = timeDefensor[defensor].defesa;
}

        int dano = timeAtacante[atacante].ataque - defesa_final;        //calculo do dano
            if (dano < 0) dano = 0;

                                                                            
        if (timeAtacante[atacante].classe == 0 && (rand() % 100) < 20) {     // Habilidades especiais
        printf(" Golpe Critico\n");
        dano *= 2;
    }
        if (timeAtacante[atacante].classe == 1 && (rand() % 100) < 25) {

            printf(" Bola de Fogo! Defesa ignorada.\n");
        dano = timeAtacante[atacante].ataque;
    }
        if (timeAtacante[atacante].classe == 2 && (rand() % 100) < 15) {

            printf(" Ataque Duplo\n");
        dano *= 2;
    }

        timeDefensor[defensor].vida -= dano;  //aplica o dano

        if (timeDefensor[defensor].vida < 0)
            timeDefensor[defensor].vida = 0;

        printf(" Dano aplicado: %d\n", dano);

        if (timeDefensor[defensor].classe == 3 && timeDefensor[defensor].vida > 0 &&  //habilidade de cura do paladino
            (rand() % 100) < 30) {
        int vida_perdida = 100 - timeDefensor[defensor].vida;

        int cura = vida_perdida * 0.2;

            timeDefensor[defensor].vida += cura;

        if (timeDefensor[defensor].vida > 100)

            timeDefensor[defensor].vida = 100;
        printf(" Paladino regenerou %d de vida\n", cura);
    }

        printf("\n");
}

    void mostrarStatus(struct personagem time[], int tamanho) {     //exibe as informações de cada personagem após cada turno
        for (int i = 0; i < tamanho; i++) {

            mostrarClasse(time[i].classe);
        printf(" Vida %d  ", time[i].vida);
    }
        printf("\n");
}
 

int main ()
{
    
    struct personagem time1[5], time2[5];

        time1[0].classe = 0; time1[0].vida = 100; time1[0].ataque = 20; time1[0].defesa = 10; //define os personagens do primeiro time
        time1[1].classe = 1; time1[1].vida = 100; time1[1].ataque = 30; time1[1].defesa = 5;
        time1[2].classe = 2; time1[2].vida = 100; time1[2].ataque = 18; time1[2].defesa = 8;
        time1[3].classe = 3; time1[3].vida = 100; time1[3].ataque = 15; time1[3].defesa = 12;
        time1[4].classe = 4; time1[4].vida = 100; time1[4].ataque = 25; time1[4].defesa = 6;

        int i;

            for (i = 0; i < 5; i++) {      //laço de repetição para passar as informações ao outro time(mesmos personagens dos dois lados)
                time2[i] = time1[i];
    }

    srand(time(NULL)) ; //semente de inicialização do sorteio

        int turno = rand() % 2 ;    //sorteia a equipe que vai começar

            int rodada = 1;

        while (equipeMorta(time1) == 0 && equipeMorta(time2) == 0) {
            printf(" Rodada %d:\n", rodada);

        if (turno == 0) {           //ataques de cada tima
            int atacante = escolherAtacante(time1);
            int defensor = escolherDefensor(time2);
            realizarAtaque(time1, atacante, time2, defensor);
        } else {
            int atacante = escolherAtacante(time2);
            int defensor = escolherDefensor(time1);
            realizarAtaque(time2, atacante, time1, defensor);
        }

        printf("Estado Atual:\nTime 1: "); //exibe estado atual dos personagens
            mostrarStatus(time1, 5);

        printf("Time 2: ");
        mostrarStatus(time2, 5);

            turno = 1 - turno;  //novo turno
            rodada++;
    }

        if (equipeMorta(time1) == 1 && equipeMorta(time2) == 1) {       //apresenta o resultado 

            printf("Empate Ambos os times morreram.\n");
        } else if (equipeMorta(time1) == 1) {
            printf("Time 2 venceu!\n");

        } else {
            printf("Time 1 venceu!\n");
    }

    return 0;
}

           
            
    


    