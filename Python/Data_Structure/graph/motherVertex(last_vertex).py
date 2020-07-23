
def dfs(i,visited):
	if not visited[i]:
		visited[i] = True
		for j in adjlist[i]:
			dfs(j,visited)


if __name__ == "__main__":
	adjlist = [[] for i in range(int(input("enter number of vertex:")))]
	for i in range(int(input("enter number of edges:"))):
		s,d = map(int,input("enter src and dst:").split())
		adjlist[s].append(d)
	print(adjlist)

	visited = [False for j in range(len(adjlist))]
	last = 0
	for j in range(len(adjlist)):
		if not visited[j]:
			dfs(j,visited)
			last = j

	visited = [False for j in range(len(adjlist))]
	dfs(last,visited)
	print(last,visited)
	if all(visited):
		print("mother vertex is",last)


