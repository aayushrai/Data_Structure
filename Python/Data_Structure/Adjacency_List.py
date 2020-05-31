class Node:
    def __init__(self,vertex):
        self.vertex = vertex
        self.next = None
    
class Adjacency_list:
    def __init__(self,vertices):
        self.vertices = vertices
        self.graph = [None]*vertices
    def add_edge(self,src,dst):
        # creating edge from src to dst
        node = Node(dst)
        node.next = self.graph[src]
        self.graph[src] = node

        # remove code below for directed graph
        # creating edge from dst to src
        node = Node(src)
        node.next = self.graph[dst]
        self.graph[dst] = node
    
    def print_graph(self): 
        for i in range(len(self.graph)): 
            print("Adjacency list of vertex {}\n head".format(i), end="") 
            temp = self.graph[i] 
            while temp: 
                print(" -> {}".format(temp.vertex), end="") 
                temp = temp.next
            print(" \n") 

    def printedges(self,vertex):
        node = self.graph[vertex]
        while node and node.next:
            print(node.vertex)
            node = node.next


if __name__ == "__main__":
    # vertices = int(input())
    # edges = int(input())
    # graph = Adjacency_list(vertices)
    # for i in range(edges):
    #     src,dst = map(int,input().split())
    #     graph.add_edge(src,dst)
    # graph.printedges(2)
    V = 5
    graph = Adjacency_list(V) 
    graph.add_edge(0, 1) 
    graph.add_edge(0, 4) 
    graph.add_edge(1, 2) 
    graph.add_edge(1, 3) 
    graph.add_edge(1, 4) 
    graph.add_edge(2, 3) 
    graph.add_edge(3, 4) 
  
    graph.print_graph() 
