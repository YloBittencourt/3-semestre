#include <stdio.h>
#include <stdlib.h>
//Estruturas e fun��es do slide
struct elemento {
  int valor;
  struct elemento *prox;
};

typedef struct elemento No;
typedef struct elemento *Pno;

/* Percorre e imprime a lista. Recebe o in�cio da lista */
void mostrarLista(Pno inicio) {
  Pno atual;
  atual = inicio;
  do {
    printf("%d ", atual->valor);
    atual = atual->prox;
  } while (atual != inicio);
  printf("\n");
}

/* Recebe dados (valor) e retorna um elemento com esse dado */
Pno criaElemento(int valor) {
  Pno novo;
  novo = (Pno)malloc(sizeof(No));

  novo->valor = valor;
  novo->prox = NULL;

  return novo;
}

/* Verifica se a lista est� vazia. Se estiver, retorna 1; caso contr�rio, retorna 0. */
int vazia(Pno inicio) {
  if (inicio == NULL)
    return 1;
  else
    return 0;
}

/* Fun��o para inserir um n� no in�cio da lista, mantendo a propriedade circular */
void insereInicio(Pno *inicio, Pno *novo) {
  Pno ultimo = *inicio;

  if (vazia(*inicio)) {
    *inicio = *novo;
    (*inicio)->prox = *inicio; // mant�m a propriedade circular
  } else {
    (*novo)->prox = *inicio;

    // Encontra o �ltimo elemento
    while (ultimo->prox != *inicio)
      ultimo = ultimo->prox;

    *inicio = *novo;
    ultimo->prox = *novo; // mant�m a propriedade circular
  }
}

/* Fun��o para deslocar um n� da posi��o i para a frente */
Pno deslocarNoParaFrente(Pno inicio, int i) {
  if (vazia(inicio) || inicio->prox == inicio) {
    return inicio;
  }
  Pno atual = inicio;
  Pno anterior = NULL;

  int contador = 0;
  while (contador < i) {
    anterior = atual;
    atual = atual->prox;
    contador++;
  }

  if (atual == inicio) {
    return inicio; // O n� a ser movido j� est� na primeira posi��o
  }

  if (anterior != NULL) {
    anterior->prox = atual;
  }

  Pno temp = atual;
  while (temp->prox != inicio) {
    temp = temp->prox;
  }

  temp->prox = inicio;
  inicio = atual;

  return inicio;
}

int main() {
  Pno inicio = NULL;

  // Inserir alguns elementos na lista (exemplo a lista da prova), mas funciona com 2,3 ou n elementos, pode remover 1 ou 2 dessas op��es para testar
  Pno novo1 = criaElemento(22);
  Pno novo2 = criaElemento(21);
  Pno novo3 = criaElemento(20);
  Pno novo4 = criaElemento(10);

  // Chamar a fun��o para inserir no in�cio da lista
  insereInicio(&inicio, &novo1);
  insereInicio(&inicio, &novo2);
  insereInicio(&inicio, &novo3);
  insereInicio(&inicio, &novo4);

  //Mostrar a lista original primeiro
  printf("Lista original: ");
  mostrarLista(inicio);

  int posicao; // Nova vari�vel para saber a posi��o que foi desejada a ser trocada
  printf("Posi��o para mover: ");
  scanf("%d", &posicao);
  inicio = deslocarNoParaFrente(inicio, posicao);

  printf("Lista ap�s mover o n� da posi��o %d para frente: ", posicao);
  mostrarLista(inicio); // mostrar a lista ap�s a mudan�a

  return 0;
}

//Como a lista � circular, se for escolhido, o ultimo elemento deve ser colocado para frente passa a ser o primeiro, e o que estava em primeiro eu coloquei para segundo, fiquei na d�vida se deveria ser o segundo ou �ltimo, mas entendi como segundo
//Pensei que seria o segundo pela l�gica caso tenha 2 elementos, o ultimo escolhido seria o primeiro e o primeiro o segundo, ent�o para mais elementos a l�gica seria a mesma
