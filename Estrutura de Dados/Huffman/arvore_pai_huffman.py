
class No:
    """Esta classe representa um nó/elemento de uma árvore.
       Equivalente a função criar_arvore em C -- no slide
    """ 
    def __init__(self, valor, esquerda=None, direita=None):
        self.valor = valor
        self.esquerda = esquerda
        self.direita = direita
        self.pai=None
        # se nao é nulo, atualiza ponteiro de pai 
        if self.esquerda:
            self.esquerda.pai=self
        if self.direita:
            self.direita.pai=self
            

class Arvore:
    """Esta classe contem funções para a manipulação de árvores binárias."""
    
    # Recebe um Nó de uma árvore (raiz local) e um inteiro.
    # Retorna o No que contem o valor inteiro.
    def procurar_no (raiz: No, x: int) -> No:
        
        if raiz is None:
            return None
        
        if raiz.valor == x:
            return raiz
        
        esq = Arvore.procurar_no(raiz.esquerda, x)
        if (esq is not None):
            return esq
        
        _dir = Arvore.procurar_no(raiz.direita, x)
        if (_dir is not None):
            return _dir
        
        return None

    def numero_nos(raiz: No) -> int:
        if raiz is None:
            return 0
        n_esq=Arvore.numero_nos(raiz.esquerda)
        n_dir=Arvore.numero_nos(raiz.direita)
        return n_esq+n_dir+1
    
    def altura(raiz: No) -> int:
        if raiz is None:
            return 0
        h_esq = Arvore.altura(raiz.esquerda)
        h_dir = Arvore.altura(raiz.direita)
        return 1 + max(h_esq, h_dir)

    def pre_ordem(raiz: No):
        if raiz is not None:
            print(raiz.valor, end=' ')
            Arvore.pre_ordem(raiz.esquerda)
            Arvore.pre_ordem(raiz.direita)
            
    def pos_ordem(raiz: No):
        if raiz is not None:
            Arvore.pos_ordem(raiz.esquerda)
            Arvore.pos_ordem(raiz.direita)
            print(raiz.valor, end=' ')
    
    def in_ordem(raiz: No):
        if raiz is not None:
            Arvore.in_ordem(raiz.esquerda)
            print(raiz.valor, end=' ')
            Arvore.in_ordem(raiz.direita)
            
            
    def percurso_em_largura (raiz: No):
        f = list()
        f.append(raiz) #insere no fim
        while len(f)>0:
            raiz = f.pop(0) # removo no início
            if raiz is not None:
                f.append(raiz.esquerda)
                f.append(raiz.direita)
                print(raiz.valor, end=' ')
                
                
                
############# Uso das funções criadas

novo_1 = No(30)
novo_2 = No(10)
novo_3 = No(20, novo_2, novo_1)

novo_1 = No(40)
novo_2 = No(50, novo_1, novo_3)

# árvore montada na variável novo_2: 
#       50
# 40        20
#         10   30

print("Número de nós na árvore: ", Arvore.numero_nos(novo_2))
print("Altura da árvore: ", Arvore.altura(novo_2))

print("Percurso em ordem: ")
Arvore.in_ordem(novo_2)

print("\nPercurso em largura: ")
Arvore.percurso_em_largura(novo_2)


# dada uma árvore, buscamos o valor/caractere escolhido.
# Uma vez encontrado o caractere, vamos subindo na árvore, visitando seu pai, até o inicio da árvore
# a cada subida checados se é o filho da direita (add 0) ou esquerda (add 1)

def cod_huffman(raiz: No, alvo)->str:
    cod=[]
    aux = Arvore.procurar_no(raiz, alvo)
    while aux.pai: # mesmo que no_alvo.pai is not None
        if aux.pai.esquerda == aux: # aux é filho da esquerda
            cod.insert(0, '0') #insere no início
        else:
            cod.insert(0, '1') 
        aux=aux.pai
    return ''.join(cod) #converte a lista em string, concatenando os elementos

# Usando a função para ver o código do elemento de valor 30
# Aqui, nossa árvore contem inteiros. A de vocês terá o caractere e frequência, 
# basta adaptar para buscar o caractere 'a' ao inves do inteiro '30'
a=cod_huffman(novo_2, 30)

print('\nCod para o elemento 30:', a)
