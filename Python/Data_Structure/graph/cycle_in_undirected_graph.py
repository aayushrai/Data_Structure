from collections import defaultdict

def isCycleUtil(adjList,visited,curr):
    if visited[curr] == 2:
        return True
    visited[curr] = 1
    for j in range(len(adjList[curr])):
        if visited[adjList[curr][j]] == 1:
           visited[adjList[curr][j]] = 2
        else:
            if(isCycleUtil(adjList,visited.copy(),adjList[curr][j])):
                return True
    return False
def isCycle(adjList):
    visited = [0]*len(adjList)
    for i in range(len(adjList)):
         visited[i] = 1
         for j in range(len(adjList[i])):
            if(isCycleUtil(adjList,visited.copy(),adjList[i][j])):
                return True
         visited[i] = 0
    return False



if __name__ == "__main__":
    # adjList = defaultdict(list)
    V = int(input("Enter the number of Vertices:"))
    E = int(input("Enter the number of Edges:"))
    adjList = [[] for i in range(V)]
    for i in range(E):
        src,dst = map(int,input().split())
        adjList[src].append(dst)
        adjList[dst].append(src)
    print(adjList)
    print(isCycle(adjList))