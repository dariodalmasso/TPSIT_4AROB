class Node():
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None




def insertNode(root, key):
    if(root is None):
        root = Node(key)
    else:
        if key > root.key:
            insertNode(root.right, key)
        elif key < root.key:
            insertNode(root.left, key)


def printTree(root):
    printTree(root.left)
    if root is not None:
        printTree(root.key)
    print(root.right)
    


def main():
    root = Node(45)


if __name__=="__main__":
    main()
