


def FloydWarshal(adjMat,vertex):
	for intermediate in range(vertex):
		for src in range(vertex):
			for dst in range(vertex):
				adjMat[src][dst] = min(adjMat[src][dst],adjMat[src][intermediate]+adjMat[intermediate][dst])
	return adjMat



if __name__ == "__main__":
	inf = float('inf')
	vertex = int(input("enter number of vertex:"))
	adjMat = []
	for i in range(vertex):
		adj = []
		for j in range(vertex):
			if i == j:
				adj.append(0)
			else:
				adj.append(inf)
		adjMat.append(adj)

	for i in range(int(input("enter number of edges:"))):
		src,dst,cost= map(int,input("enter src,dst and cost:").split())
		adjMat[src][dst] = cost
	minDistanceMatrix = FloydWarshal(adjMat.copy(),vertex)
	print(minDistanceMatrix)


