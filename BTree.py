class Node:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None

class Btree:
    def __init__(self):
        self.root = None

    def insert(self,value):
        if self.root == None:
            self.root = Node(value)
        else:
            self._insert(self.root,value)

    def _insert(self,nd,value):
        if value < nd.value:
            if nd.left == None:
                nd.left = Node(value)
            else:
                self._insert(nd.left,value)
        elif value > nd.value:
            if nd.right == None:
                nd.right = Node(value)
            else:
                self._insert(nd.right,value)

        else:
            print("value in tree already!!")

    def print_tree(self):
        if self.root != None:
               self._print_tree(self.root)

    def _print_tree(self,curr_node):
        if curr_node != None:
            self._print_tree(curr_node.left)
            print(curr_node.value)
            self._print_tree(curr_node.right)

b = Btree()
b.insert(6)
b.insert(1)
b.insert(2)
b.insert(7)
b.insert(3)
b.insert(55)
b.insert(44)
b.print_tree()
b.insert(44)