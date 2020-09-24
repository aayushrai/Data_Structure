from collections import defaultdict

class Graph: 
    def __init__(self,vertices): 
        self.graph = defaultdict(list) #dictionary containing adjacency List 
        self.V = vertices #No. of vertices 
  
    # function to add an edge to graph 
    def addEdge(self,u,v): 
        self.graph[u].append(v) 

    def topo_util(self,node,visited,stack):
    	for j in self.graph[node]:
    		if not visited[j]:
    			visited[j] = True
    			self.topo_util(j,visited,stack)
    	stack.append(node)


    def topologicalSort(self):
    	visited = [False for i in range(self.V)]
    	stack = []
    	for i in range(self.V):
    		if not visited[i]:
    			visited[i] = True
    			self.topo_util(i,visited,stack)
    	print(stack[::-1])



  



g= Graph(6) 
g.addEdge(5, 2); 
g.addEdge(5, 0); 
g.addEdge(4, 0); 
g.addEdge(4, 1); 
g.addEdge(2, 3); 
g.addEdge(3, 1); 
g.topologicalSort()



  