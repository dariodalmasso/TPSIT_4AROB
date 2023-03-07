import random


class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

    def insert(self, key):
        pass

    def printTree(self, level=0): # il livello sarà inizializzato a 0.
        if self.left is not None:
            self.left.printTree(level + 1)
        print(f"Livello {level} -> {self.key}")

        if self.right is not None:
            self.right.printTree(level + 1)

    def insertNode(self, key):
        if self.key is not None:
            if key > self.key:  # chiave maggiore
                if self.right is None:
                    self.right = Node(key)
                else:
                    self.right.insertNode(key)

            elif key < self.key:  # chiave minore
                if self.left is None:
                    self.left = Node(key)
                else:
                    self.left.insertNode(key)
        else:
            self.key = key
#algoritmo di ricerca di un key in un albero
    def findNode(self, key):
        tro = False

        if self.key is not None:
            if key > self.key:  # chiave maggiore
                if self.right is not None and key == self.right:
                    tro = True
                    print("beccato")
                else:
                    self.right.findNode(key)

            elif key < self.key:  # chiave minore
                if self.left is not None and key == self.left:
                    tro = True
                    print("beccato")
                else:
                    self.left.findNode(key)
        else:
            print("non c'è")

def bilanciaAlbero(nodes):#lista di nodi
        
        l = len(nodes)
        if l == 0:
            return None #serve per terminare la ricorsione
        nodes.sort()
        m = l // 2 #divisione intera con 2 //
        root = Node(nodes[m])#istanza di oggetto nodo dove come chiave gli passo il mezzo della lista
        root.left = bilanciaAlbero(nodes[0:m])
        root.right = bilanciaAlbero(nodes[m+1:])
        return root
        


def printTree(root):
    printTree(root.left)
    if root is not None:
        printTree(root.key)
    printTree(root.right)


def main():
    lista_key = list(range(0, 40, 5))
    random.shuffle(lista_key)
    print(lista_key)

    albero = bilanciaAlbero(lista_key)

    """albero = Node(lista_key[0])
    for key in lista_key[1:]:  # dal secondo elemento (cicla su elemento)
        albero.insertNode(key)"""

    albero.printTree()
    albero.findNode(25)


if __name__ == "__main__":
    main()
