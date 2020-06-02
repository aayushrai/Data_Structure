class Node:
     def __init__(self,val):
         self.val = val
         self.next = None

class Graph:
    def __init__(self,V):
        self.vertices = V
        self.nodes = [None]*self.vertices
    
    def add_edges_directed_graph(self,src,dst):
        node = Node(dst)
        node.next = self.nodes[src]
        self.nodes[src] = node
    def isCycle(self):
        


if __name__ == "__main__":
    print()
    V = int(input("Enter number of vertices:"))
    E = int(input("Enter number of Edges:"))
    graph = Graph(V)
    print("Enter Edges:-")
    for i in range(E):
        src,dst = map(int,input().split())
        graph.add_edges_directed_graph(src,dst)
    print(graph.isCycle())

