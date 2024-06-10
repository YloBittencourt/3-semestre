#Definimos uma classe 'No',que contém um caractere,frequência e os filhos esquerdo e direito
class No:
    def __init__(self, c, freq, esq=None, dir=None):
        self.c = c
        self.freq = freq
        self.dir = dir
        self.esq = esq

#Função que constrói a árvore de Huffman a partir de uma lista de nós.
def arvore(lista_nos):
    while len(lista_nos) > 1:
        # Ordenamos os nós através das frequências.
        lista_nos.sort(key = frequencia)
        # Pegamos os dois nós de menor frequência,removemos e guardamos nas variáveis 'esquerda' e 'direita'.
        esquerda = lista_nos.pop(0)
        direita = lista_nos.pop(0)
        # Criamos um novo nó que representa a combinação dos dois nós anteriores.
        novoNo = No(None, esquerda.freq + direita.freq, esquerda, direita) 
        # Adicionamos o novo nó à lista.
        lista_nos.append(novoNo)
    # Ao final,retornamos o nó raiz da árvore
    return lista_nos[0]

#Função que retorna a frequência do nó
def frequencia(no):
    return no.freq

#Função que gera os códigos de Huffman para cada caractere na árvore
def gerandocodigos(raiz, binario, codigo):
    #Se o nó é uma folha,atribuímos o código binário ao caractere no dicionário
    if raiz.c is not None:
        codigo[raiz.c] = binario
    #Se não,chamamos recursivamente a função para os filhos esquerdo(adicionando '0') e direito(adicionando '1')
    else:
        gerandocodigos(raiz.esq, binario + "0", codigo)
        gerandocodigos(raiz.dir, binario + "1", codigo)

#Função que codifica o texto original usando os códigos de Huffman gerados
def textocodificado(texto, codigo):
    #A lista 'bits' é criada associando cada caractere do texto aos seus códigos de Huffman.
    bits = [codigo[c] for c in texto]
    #Esses códigos são acumulados para formar a sequência binária que é retornada
    return "".join(bits)

#Entrada do texto 
entrada_de_texto = """e da vez que eu me perdi no caminho so consigo lembrar de tu me sorrindo sentada no portao da tua casa lembro do cd
de coco do cafe caboclo da vontade absurda de sentir teu gosto feito fumaca num quarto fechado uu tomou conta dos
quatro cantos acende o cigarro queima a brasa eu sou o quarto tu a fumaca e os cigarros foram tantos feito fumaca num
quarto fechado tu tomou conta dos quatro cantos acende o cigarro, queima a brasa eu sou o quarto tu a fumaca e os cigarros foram tantos
e da vez que eu me perdi no caminho so consigo lembrar de tu me sorrindo sentada no portão da tua casa lembro do cd
de coco do cafe caboclo da vontade absurda de sentir teu gosto laia laia laia laia"""

#entrada_de_texto = input("Entrada de texto (em uma única linha, sem acento e sem pontuação): ")

#Calculamos as frequências de cada caractere na entrada,usando o método 'get'
frequencias = {}
for c in entrada_de_texto:
    frequencias[c] = frequencias.get(c, 0) + 1

#Criamos uma lista de nós,em que cada nó representa um caractere e sua frequência.
lista_nos = [No(c, f) for c, f in frequencias.items()]

#Construímos a árvore de Huffman a partir da lista de nós.
raiz_arvore = arvore(lista_nos)

#Inicializamos um dicionário vazio para armazenar os códigos de Huffman para cada caractere.
codigos_caracteres = {}

# Gera os códigos de Huffman e armazena em 'codigos_caracteres'.
gerandocodigos(raiz_arvore, "", codigos_caracteres)

#Codificamos o texto original chamando a função 'textocodificado' e guardamos em 'texto_codificado'
texto_codificado = textocodificado(entrada_de_texto, codigos_caracteres)

#Imprimimos as frequências e os códigos de Huffman para cada caractere.
print("Mostrando frequência e o código para cada caractere:")
for c, f in frequencias.items():
    print(f"{c}-> frequência: {f} / código: {codigos_caracteres[c]}")

#Imprimimos o texto já codificado.
print("\nTexto codificado:")
print(texto_codificado)