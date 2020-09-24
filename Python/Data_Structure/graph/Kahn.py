from collections import defaultdict

class Graph: 
    def __init__(self,vertices): 
        self.graph = defaultdict(list) #dictionary containing adjacency List 
        self.V = vertices #No. of vertices 
  
    # function to add an edge to graph 
    def addEdge(self,u,v): 
        self.graph[u].append(v) 

    def topological_sort(self):
        sorted1 = []
        indegree = [0 for i in range(self.V)]
        Q = []
        for i in range(self.V):
            for j in self.graph[i]:
                indegree[j] += 1
        for i in range(self.V):
            if indegree[i] == 0:
                Q.append(i)
        

        while Q:
            node = Q.pop()
            sorted1.append(node)
            for i in self.graph[node]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    Q.append(i)

        if len(sorted1) != self.V:
            print("graph is not DAG")
        else:
            print(sorted1)
        








g= Graph(6) 
g.addEdge(5, 3); 
g.addEdge(5, 0); 
g.addEdge(4, 0); 
g.addEdge(4, 1); 
g.addEdge(2, 1); 
g.addEdge(3, 2); 
g.topological_sort()



  