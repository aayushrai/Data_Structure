

def dfs(i,visited):
	if not visited[i]:
		visited[i] = True
		for j in adjlist[i]:
			dfs(j,visited)
	return visited



if __name__ == "__main__":
	adjlist = [[] for i in range(int(input("enter number of vertex:")))]
	for i in range(int(input("enter number of edges:"))):
		s,d = map(int,input("enter src and dst:").split())
		adjlist[s].append(d)
	print(adjlist)

	visited = [False for j in range(len(adjlist))]
	for j in range(len(adjlist)):
		ans = dfs(j,visited.copy())
		print(ans)
		if all(ans):
			print("mother vertex is",j)


