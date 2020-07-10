class Graph:
	def __init__(self,vertex):
		self.adjMat = [[0 for i in range(vertex)] for j in range(vertex)]
		self.vertex = vertex

	def addEdgeDirectedGragh(self,src,dst):
		self.adjMat[src][dst] = 1
		print("add Edge succefully")

	def addEdgeUndirectedGraph(self,src,dst):
		self.adjMat[src][dst] = 1
		self.adjMat[dst][src] = 1
		print("add Edge succefully")

	def removeEdgeDirectedGraph(self,src,dst):
		self.adjMat[src][dst] = 0
		print("remove Edge succefully")

	def removeEdgeUndirectedGraph(self,src,dst):
		self.adjMat[src][dst] = 0
		self.adjMat[dst][src] = 0
		print("remove Edge succefully")
		

if __name__ == "__main__":

	graph = Graph(int(input("Enter number of vertex:")))
	typ =  int(input('Directed: 1, Undirected: 0\n'))

	for i in range(int(input("Enter number of Edges:"))):
		src,dst = map(int,input("Enter source and destination:").split())
		graph.addEdgeDirectedGragh(src-1,dst-1) if typ == 1 else graph.addEdgeUndirectedGraph(src-1,dst-1)

	print(graph.adjMat)
