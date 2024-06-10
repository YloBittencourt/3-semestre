class Atleta:
    def __init__(self, nome, ouro, prata, bronze):
        self.nome = nome
        self.ouro = ouro
        self.prata = prata
        self.bronze = bronze

def troca(atletas, idx1, idx2):
    atletas[idx1], atletas[idx2] = atletas[idx2], atletas[idx1]

def maior(a1, a2):
    if a1.ouro > a2.ouro or \
            (a1.ouro == a2.ouro and a1.prata > a2.prata) or \
            (a1.ouro == a2.ouro and a1.prata == a2.prata and a1.bronze > a2.bronze):
        return True
    return False

def bubbleSort(atletas):
    n = len(atletas)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if maior(atletas[j], atletas[j + 1]):
                troca(atletas, j, j + 1)

if __name__ == "__main__":
    num_atletas = int(input("Quantidade de atletas: "))
    atletas = []
    
    for i in range(num_atletas):
        nome = input(f"Nome do {i+1} atleta: ")
        ouro = int(input("Ouro: "))
        prata = int(input("Prata: "))
        bronze = int(input("Bronze: "))
        atleta = Atleta(nome, ouro, prata, bronze)
        atletas.append(atleta)

    bubbleSort(atletas)

    print("\nOrdem:")
    for atleta in atletas:
        print(atleta.nome)
