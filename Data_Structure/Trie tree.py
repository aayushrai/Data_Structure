class Node:
    def __init__(self):
        self.children = [None]*26
        self.wordEnd = False

class Trie:
    def __init__(self):
        self.root = Node()

    def get_index(self,ch):
        return ord(ch) - ord("a")

    def insert(self,string):
        curr = self.root
        for s in string:
            index = self.get_index(s)
            if not curr.children[index]:
                curr.children[index] = Node()
            curr = curr.children[index]
        curr.wordEnd = True

    def search(self,string):
        curr = self.root
        for s in string:
            index = self.get_index(s)
            if not curr.children[index]:
                return False
            curr = curr.children[index]
        if curr.wordEnd == True:
            return True
        return False

    def prefix(self,string):
        curr = self.root
        for s in string:
            index = self.get_index(s)
            if not curr.children[index]:
                return False
            curr = curr.children[index]
        return True

t = Trie()
t.insert("abbbc")
t.insert("abddffs")
t.insert("abs")
print(t.prefix("abd"))
print(t.search("fgsgg"))