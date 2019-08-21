class node:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None

class Btree:
    def __init__(self):
        self.root = None

    def insert(self,value):
        if self.root == None:
            self.root = node(value)
        else:
             self._insert(value,self.root)

    def _insert(self,value,nd):
        if value < nd.value:
            if nd.left == None:
                nd.left = node(value)
            else:
                self._insert(value, nd.left)
        elif value > nd.value:
            if nd.right == None:
                nd.right = node(value)
            else:
                self._insert(value,nd.right)

        else:
            print("already in list")

    def print_tree(self,order="inorder"):
        if self.root == None:
            print("empty")
        else:
            self._print_tree(self.root,order)

    def _print_tree(self,nd,order="inorder"):
        if nd:
            if order == "inorder":
                self._print_tree(nd.left)
                print(nd.value)
                self._print_tree(nd.right)
            if order == "preorder":
                print(nd.value)
                self._print_tree(nd.left)
                self._print_tree(nd.right)
            if order == "postorder":
                self._print_tree(nd.left)
                self._print_tree(nd.right)
                print(nd.value)


b = Btree()
b.insert(6)
b.insert(1)
b.insert(2)
b.insert(7)
b.insert(3)
b.insert(55)
b.insert(44)
print("PREORDER")
b.print_tree("preorder")
print("INORDER")
b.print_tree("inorder")
print("POSTORDER")
b.print_tree("postorder")
b.insert(44)