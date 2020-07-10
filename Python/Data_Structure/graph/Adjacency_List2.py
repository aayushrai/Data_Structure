class Graph:
	def __init__(self,vertex):
		self.adjList = [[] for i in range(vertex)]

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


if __name__ == "__main__":

	graph = Graph(int(input("Enter number of vertex:")))
	typ =  int(input('Directed: 1, Undirected: 0\n'))

	for i in range(int(input("Enter number of Edges:"))):
		src,dst = map(int,input("Enter source and destination:").split())
		graph.addEdgeDirectedGragh(src-1,dst-1) if typ == 1 else graph.addEdgeUndirectedGraph(src-1,dst-1)

	print(graph.adjList)

  

