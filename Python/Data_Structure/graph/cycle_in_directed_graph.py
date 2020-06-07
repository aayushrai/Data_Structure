from collections import defaultdict

class Graph:
    def __init__(self,V):
        self.vertices = V
        self.node = defaultdict(list)

    def add_edges_directed_graph(self,src,dst):
        self.node[src].append(dst)

    def printList(self):
        print(self.node)

    def isCycle(self):
        visited = [False]*self.vertices
        for i in range(self.vertices):
            visited[i] = True
            for j in range(len(self.node[i])):
                if(self.isCycleUtil(self.node[i][j],visited)):
                    return True
            visited[i] = False
        return False
        
    def isCycleUtil(self,curr,visited):
        if visited[curr] == True:
            return True
        visited[curr] = True
        for i in range(len(self.node[curr])):
            if(self.isCycleUtil(self.node[curr][i],visited.copy())):
                return True
        return False


        

if __name__ == "__main__":
    print()
    V = int(input("Enter number of vertices:"))
    E = int(input("Enter number of Edges:"))
    graph = Graph(V)
    print("Enter Edges:-")
    for i in range(E):
        src,dst = map(int,input().split())
        graph.add_edges_directed_graph(src,dst)
    print(graph.printList())
    print(graph.isCycle())

