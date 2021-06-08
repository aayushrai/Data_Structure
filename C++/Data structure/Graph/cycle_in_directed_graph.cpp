#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Time complexity O(V+E)
//Space complexity O(V)

int isCycleUtil(vector<int> adjList[],vector<bool> visited,int curr){
    if(visited[curr]==true)
       return true;
    visited[curr]=true;
       for(int j=0;j < adjList[curr].size();j++){
           if(isCycleUtil(adjList,visited,adjList[curr][j]))
                 return true;
       }
       return false;
}

int isCycle(vector<int> adjList[],int V){
    vector<bool> visited(V,false);
    for(int i=0;i < V;i++){
        visited[i] = true;
       for(int j=0;j < adjList[i].size();j++){
           if(isCycleUtil(adjList,visited,adjList[i][j]))
               return true;
       }
       visited[i]= false;
    }
    return false;
}



int main()
{
    int V,E,src,dst;
    cout << "enter number of vertices:";
    cin >> V;
    cout << "enter number of Edges:";
    cin >> E;
    
    vector<int> adjList[V];
    for(int i =0;i<E;i++)
    {
        cout << "enter edge src dst:";
        cin >> src >> dst;
        // directed graph
        adjList[src].push_back(dst);
    }
    cout << isCycle(adjList,V);
}
