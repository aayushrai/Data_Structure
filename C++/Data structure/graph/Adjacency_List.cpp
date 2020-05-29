#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> g[],int src,int dst)
{ 
    g[src].push_back(dst);
    g[dst].push_back(src);//comment this line for directed graph
}
void printAdjList(vector<int> g[],int v)
{ 
  for(int i=0;i<v;i++){
      cout << "\n Adjacency list of vertex "<< i << "\n head "; 
  for(auto x:g[i])
      cout << "-> " << x;
  printf("\n"); 

  }
}
int main()
{
    int e,src,dst,v;
    cout << "enter number of Vertices";
    cin >> v;
    cout << "enter number of Edges";
    cin >>e;
    vector<int> g[v];
    while(e--){
        cin >> src >> dst;
        addEdge(g,src,dst);
    }
    printAdjList(g,v);
    return 0;
}