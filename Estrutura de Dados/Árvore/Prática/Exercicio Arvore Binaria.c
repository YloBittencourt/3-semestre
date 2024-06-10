#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da árvore (slide)
typedef struct No {
  int dado;
  struct No *esq, *dir;
}No;
typedef No* p_no;

// Função para criar um nó da árvore (slide)
p_no criar_arvore(int x, p_no esq, p_no dir) {
  p_no r = malloc(sizeof(No));
  r->dado = x;
  r->esq = esq;
  r->dir = dir;
  return r;
}

// Função para ordem da árvore (slide)
void pre_ordem(p_no raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->dado); // visita raiz
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
  }
}

// Função para calcular o número de folhas em uma árvore (Letra A)
int quantidade_folha(p_no raiz) {
  // Se a raiz é NULL, não vai existir folhas pois não existe uma árvore
  if (raiz == NULL) {
    return 0;
  }

  // Se é uma folha, retorna 1
  if (raiz->esq == NULL && raiz->dir == NULL) {
    return 1;
  }

  // Chamada recursiva para esquerda e direita
  int esquerda = quantidade_folha(raiz->esq);
  int direita = quantidade_folha(raiz->dir);

  //Retornar a quantidade de folhas da direita + a quantidade de folhas da esquerda
  return esquerda + direita;
}

// Função recursiva para apagar folha (Letra B)
p_no apagar_folhas(p_no raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    }

  //Raiz->esq NULL e Raiz->dir NULL (não tem filhos portanto é uma folha) e Raiz->dado chave (é o que deseja apagar)
  if (raiz->esq == NULL && raiz->dir == NULL && raiz->dado == chave) {
      free(raiz); // Free no valor
      return NULL;
  }

    // Chamada recursiva (pedido na questão) para apagar a folha do valor pedido, procurando na esquerda e na direita
    raiz->esq = apagar_folhas(raiz->esq, chave);
    raiz->dir = apagar_folhas(raiz->dir, chave);

    return raiz;
}

// Função para comparar duas árvores binárias (Letra C)
int comparar(p_no raiz1, p_no raiz2) {
  // Verifica se ambos os nós são NULL (chegou ao final das duas arvores)
  if (raiz1 == NULL && raiz2 == NULL) {
    // Se ambos os nós são NULL, as árvores são iguais
    return 1;
  }
  // Verifica se ambos os nós não são NULL (ainda existe nós para comparação)
  if (raiz1 != NULL && raiz2 != NULL) {
    // Compara os dados dos nós atuais e chama recursivamente a função para os nós filhos
    // Retorna verdadeiro se os dados dos nós atuais são iguais e as subárvores esquerda e direita também são iguais
    return (raiz1->dado == raiz2->dado) && comparar(raiz1->esq, raiz2->esq) && comparar(raiz1->dir, raiz2->dir);
  }
  // Se um dos nós for NULL e o outro não, as árvores são diferentes
  return 0;
}


// Função para liberar as árvores
void liberar(p_no raiz) {
  if (raiz != NULL) {
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
  }
}

int main() {
// Função A
  printf("Casos de teste para a FUNÇÃO A:\n");
// árvore1 do exemplo do slide
  p_no arvore1 = criar_arvore(1, NULL, NULL);
  printf("Árvore 1: %d folhas\n", quantidade_folha(arvore1));
// árvore2 do exemplo do slide
  p_no arvore2 =criar_arvore(6, criar_arvore(9, criar_arvore(6, NULL, NULL), criar_arvore(7, criar_arvore(7, NULL, NULL), NULL)),criar_arvore(5,NULL, criar_arvore(8, criar_arvore(5, NULL, NULL), criar_arvore(7, NULL, NULL))));
  printf("Árvore 2: %d folhas\n", quantidade_folha(arvore2));
// árvore3 do exemplo do slide
  p_no arvore3 = criar_arvore(6, criar_arvore(9, criar_arvore(6, NULL, NULL), NULL), criar_arvore(7, NULL, criar_arvore(8, criar_arvore(5, NULL, NULL), criar_arvore(7, NULL, NULL))));
  printf("Árvore 3: %d folhas\n", quantidade_folha(arvore3));

// Função B
  printf("\nCasos de teste para a FUNÇÃO B:\n");
  printf("Remover valor 1:\n");
  arvore1 = apagar_folhas(arvore1, 1); //a arvore solicitada na questão é a arvore1 e o valor é o valor 1
  pre_ordem(arvore1); //ordenar corretamente após remover
  printf("\n");

  printf("Remover valor 7:\n");
  arvore2 = apagar_folhas(arvore2, 7); //a árvore solicitada na questão é a árvore2 e o valor é o valor 7
  pre_ordem(arvore2); //ordenar corretamente após remover
  printf("\n");

  printf("Remover valor 7:\n");
  arvore3 = apagar_folhas(arvore3, 7); //a árvore solicitada na questão é a árvore3 e o valor também é o 7
  pre_ordem(arvore3); //ordenar corretamente após remover
  printf("\n");

// Função C
//OBS: no primeiro caso, criei uma arvore4 para fazer a comparação com a arvore3 após a remoção da folha com valor 7.
//Porém, no segundo caso ele compara a arvore4 com ela mesma, então eu fiz: comparar(arvore4,arvore4), poderia fazer uma outra arvore5 para comparar, mas como seria igual a formação, manti essa escolha
  printf("\nCasos de teste para a FUNÇÃO C: \n");
  //árvore igual pedida a questão
  p_no arvore4=criar_arvore(6, criar_arvore(9, criar_arvore(6, NULL, NULL), criar_arvore(7, NULL, NULL)), criar_arvore(8, NULL, criar_arvore(5, NULL, NULL)));
  //a arvore pedida na primeira comparação da questão é a arvore3 apos a remoção da folha 7 e uma nova arvore que foi criada acima(arvore4)
  printf("As árvores são iguais? %s", comparar(arvore3, arvore4) ? "\nVerdadeiro" : "\nFalso");
  //a arvore pedida na segunda comparação da questão é a arvore4 com ela mesma
  printf("\nAs árvore são iguais %s",comparar(arvore4, arvore4) ? "\nVerdadeiro":"\nFalso");

// Liberar memória
  liberar(arvore1);
  liberar(arvore2);
  liberar(arvore3);
  liberar(arvore4);

  return 0;
}