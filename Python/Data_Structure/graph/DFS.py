class Graph:
	def __init__(self,vertex):
		self.adjList = [[] for i in range(vertex)]
		self.vertex = vertex

	def addEdgeDirectedGraph(self,src,dst):
		self.adjList[src].append(dst)

	def addEdgeUndirectedGraph(self,src,dst):
		self.adjList[src].append(dst)
		self.adjList[dst].append(src)

	def removeEdgeDirectedGraph(self,src,dst):
		if dst in adjList[src]:
			adjList[src].remove[dst]

	def removeEdgeUnDirectedGraph(self,src,dst):
		if dst in self.adjList[src]:
			self.adjList[src].remove[dst]
		if src in self.adjList[dst]:
			self.adjList[dst].remove[src]

	def DFS(self,starting):

		visited = [False for i in range(self.vertex)]

		S = []
		S.append(starting)
		visited[starting] = True

		while S:
			node = S.pop(-1)
			print(node,end=" ")
			for i in self.adjList[node]:
				if not visited[i]:
					S.append(i)
					visited[i] = True
			


if __name__ == "__main__":

	graph = Graph(int(input("Enter number of vertex:")))
	typ =  int(input('Directed: 1, Undirected: 0\n'))

	for i in range(int(input("Enter number of Edges:"))):
		src,dst = map(int,input("Enter source and destination:").split())
		graph.addEdgeDirectedGraph(src,dst) if typ == 1 else graph.addEdgeUndirectedGraph(src,dst)
	print(graph.adjList)
	graph.DFS(0)

	



  

