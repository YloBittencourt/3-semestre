#include <stdio.h>
#include <stdlib.h>
// Estrutura dada na questão
struct Atleta {
  char nome[100];
  int ouro, prata, bronze;
};
// Função para realizar a troca no array (tem essa função no slide)
void troca(struct Atleta *a, struct Atleta *b) {
  struct Atleta aux = *a;
  *a = *b;
  *b = aux;
}

// Função para comparação das medalhas
int maior(struct Atleta a1, struct Atleta a2) {
  if (a1.ouro > a2.ouro || (a1.ouro == a2.ouro && a1.prata > a2.prata) ||
      (a1.ouro == a2.ouro && a1.prata == a2.prata && a1.bronze > a2.bronze))
    return 1;
  else
    return 0;
}
// Função do algoritmo bubbleSort
void bubbleSort(struct Atleta atleta[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (maior(atleta[j], atleta[j + 1]) ==
          1) // chamada da função maior que fez a comparação
        troca(&atleta[j], &atleta[j + 1]); // caso seja verdade, chama a função
                                           // para realizar a troca
    }
  }
}

int main(void) {
  struct Atleta *atleta;
  int n, i, j;
  // Receber a quantidade atletas
  printf("Quantidade de atletas: ");
  scanf("%d", &n);
  // Alocação dinâmica
  atleta = malloc(n * sizeof(struct Atleta));
  if (atleta == NULL)
    exit(-1);
  // Laço for para receber as informações de cada atleta
  for (i = 0; i < n; i++) {
    printf("\nNome do %d atleta: ", i + 1);
    scanf(" %s", &atleta[i].nome);
    printf("Ouro: ");
    scanf("%d", &atleta[i].ouro);
    printf("Prata: ");
    scanf("%d", &atleta[i].prata);
    printf("Bronze: ");
    scanf("%d", &atleta[i].bronze);
  }
  // Chamada da função bubbleSort
  bubbleSort(atleta, n);
  // Printando a ordem conforme pedido na questão
  printf("\nOrdem:\n");
  for (i = 0; i < n; i++) {
    printf("%s\n", atleta[i].nome);
  }
  // Liberando
  free(atleta);

  return 0;
}