#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Time complexity O(V+E)
//Time complexity O(V)
bool isCycle(vector<int> [],int);
bool isCycleUtil(vector<int> [],vector<int>,int);
int main()
{
    int V,E,src,dst;
    cout << "Enter number of Vertices:";
    cin >> V;
    cout << "Enter number of Edges:";
    cin >> E;
    vector<int> adjList[V];
    for(int i=0;i<E;i++){
        cin >> src >> dst;
        adjList[src].push_back(dst);
        adjList[dst].push_back(src);  //Undirected graph
    }
    cout << isCycle(adjList,V);
}

bool isCycle(vector<int> adjList[],int V){
    vector<int> visited(V,0);
    for(int i=0;i<V;i++)
    {
       visited[i] = 1;
       for(int j =0;j<adjList[i].size();j++)
       {
        if(isCycleUtil(adjList,visited,adjList[i][j]))
             return true;
       }
       visited[i] = 0;
    }
    return false;
}

bool isCycleUtil(vector<int> adjList[],vector<int> visited,int curr)
{
  if(visited[curr] == 2)
     return true;
  visited[curr] = 1;
  for(int j =0;j<adjList[curr].size();j++)
       {
        if(visited[adjList[curr][j]] == 1)
        {
            visited[adjList[curr][j]] = 2;
        }
        else
        {
            if(isCycleUtil(adjList,visited,adjList[curr][j]))
                return true;
        }
       }
    return false;
  
}
