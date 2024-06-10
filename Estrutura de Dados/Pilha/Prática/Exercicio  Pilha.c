#include <stdio.h>
#include <stdlib.h>
//M�ximo de 26 vag�es
#define max 26

typedef struct {
    char pilha_direita[max]; //Pilha do lado direito
    char pilha_esquerda[max]; //Pilha do lado esquerdo
    int topo_direita; //Topo do lado direito
    int topo_esquerda; //Topo do lado esquerdo
} Pilhas;

//Fun��o para inicializar as pilhas
void inicializar(Pilhas *p) {
    p->topo_direita = -1; //pilha direita
    p->topo_esquerda = -1; //pilha esquerda
}

void empilhar(Pilhas *p, char vagao, int lado) { // lado 1 = direito, lado 2 = esquerdo, assim fica melhor para saber o lado
    if (lado == 1) { // Lado direito
        if (p->topo_direita < max - 1) {
            p->pilha_direita[++(p->topo_direita)] = vagao; //empilhar no lado direito
        } else {
            printf("Erro: pilha do lado direito cheia.\n"); //se n�o for menor que max - 1, ent�o a pilha estar� cheia
            exit(1);
        }
    } else if (lado == 2) { // Lado esquerdo
        if (p->topo_esquerda < max - 1) {
            p->pilha_esquerda[++(p->topo_esquerda)] = vagao; //empilhar o lado esquerdo
        } else {
            printf("Erro: pilha do lado esquerdo cheia.\n"); //se n�o for menor que max - 1, ent�o a pilha estar� cheia
            exit(1);
        }
    }
}

char desempilhar(Pilhas *p, int lado) {
    if (lado == 1) { // Lado direito
        if (p->topo_direita >= 0) {
            return p->pilha_direita[(p->topo_direita)--]; //desempilhar o lado direito
        } else {
            printf("Erro: pilha do lado direito vazia.\n"); //se n�o tiver mais nada, ent�o estar� vazia
            exit(1);
        }
    } else if (lado == 2) { // Lado esquerdo
        if (p->topo_esquerda >= 0) {
            return p->pilha_esquerda[(p->topo_esquerda)--]; //desempilhar o lado esquerdo
        } else {
            printf("Erro: pilha do lado esquerdo vazia.\n"); //se n�o tiver mais nada, ent�o estar� vazia
            exit(1);
        }
    }
}

int main() {
    int num; //n�mero de vag�es
    char sequencia[max]; //sequ�ncia de vag�es
    char op; //opera��o (D ou E)
    Pilhas vagao_pilhas; //Struct pilha

    printf("N�mero de vag�es: ");
    scanf("%d", &num);

    //O n�mero m�ximo de vag�es deve ser 26
    if(num > 26){
            printf("Erro!\n");
            exit(-1);
    }

    printf("Sequ�ncia dos vag�es: ");
    scanf(" %s", sequencia);

    inicializar(&vagao_pilhas);

    int i = 0;
    printf("Sequ�ncia de opera��o: ");
  //Como o i = 0 e ap�s a itera��o ele � incrimentado (i++), ent�o um la�o while enquanto i < num
    while (i < num) {
        scanf(" %c", &op); //vai ler as opera��es
        if (op == 'E' || op == 'e') { //se a opera��o for pra esquerda
            empilhar(&vagao_pilhas, sequencia[i], 2); // 2 = Lado esquerdo
            i++; //acrescentar +1 no i apenas no lado esquerdo at� acabar os vagoes
        } else if (op == 'D' || op == 'd') { //se a opera��o for pra direita
            if (vagao_pilhas.topo_esquerda < 0) {
                printf("Erro: opera��o 'D' n�o pode ser realizada.\n"); //Se a pilha esquerda tiver vazia, n�o tem como empilhar na direita
                exit(1);
            }
            char vagao = desempilhar(&vagao_pilhas, 2); // Lado esquerdo, vai desempilhar um para empilhar depois no lado direito
            empilhar(&vagao_pilhas, vagao, 1); // Empilhando no lado direito
        }

    }

    printf("Vag�es do lado direito: ");
  //Percorrer a pilha do lado direito e imprimir os vag�es
    for (int j = 0; j <= vagao_pilhas.topo_direita; j++) {
       printf("%c ", vagao_pilhas.pilha_direita[j]);
    }
    printf("\n");

    return 0;
}

//Exemplo de entrada:
//N�mero de vag�es: 8
//Sequ�ncia de vag�es: abcdefgh ou ABCDEFGH (Se colocar D ou d com espa�o, ou seja, A B C D E ou a b c d e, ele vai interpretar o D ou d como opera��o D(ireita))
//Sequ�ncia de opera��o: EEEDEEDDDEDEE

//Exemplo de sa�da:
//C E D B F (Conforme o slide pede)
