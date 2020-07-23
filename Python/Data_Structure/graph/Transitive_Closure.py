

def transitive_closure(src,dst):
	tc[src][dst] = 1

	for i in adjlist[dst]:
		if not tc[src][i]:
			transitive_closure(src,i)



if __name__ == "__main__":
	adjlist = [[] for i in range(int(input("enter number of vertex:")))]
	for i in range(int(input("enter number of edges:"))):
		s,d = map(int,input("enter src and dst:").split())
		adjlist[s].append(d)
	print(adjlist)

	tc = [[0 for i in range(len(adjlist))]for j in range(len(adjlist))]
	for i in range(len(adjlist)):
		transitive_closure(i,i)
	print(tc)


