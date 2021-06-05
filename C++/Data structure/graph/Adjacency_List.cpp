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

// _____________________________________________________________________________________________________________________________________________________
// second approach with classes and also with weighted graph
//  we can also use pair<int,int> int place struct  vw i just experimenting
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef struct vw{
    int vertex,weight;
}vw;

class graph{
    public:
        int vertex;
        vector<vector<vw>> adjList; 
        graph(int vertex){
            this->vertex = vertex;
            this->adjList.resize(vertex,vector<vw>());
        }
        void addEdge(int src,int dst,int weight){
            vw temp = {dst,weight};
            vw temp2 = {src,weight};
            this->adjList[src].push_back(temp);
            // this->adjList[dst].push_back(temp2);  // comment this line for directed graph or uncomment for undirected graph
        }
        void diplayGraph(){
             cout << "Edges:" << "\n" ;
            for(int i=0;i<adjList.size();i++){
                for(int j=0;j<adjList[i].size();j++){
                cout << i << " " <<  adjList[i][j].vertex << " " << adjList[i][j].weight << "\n" ;
                }
            }
        }
        bool _hasPath(int src,int dst,vector<bool> visited){
            if(src == dst){
                return true;
            }
            for(vw i:adjList[src]){
                if(!visited[i.vertex]){
                    visited[i.vertex] = true;
                    if(_hasPath(i.vertex,dst,visited))
                        return true;
                }
            }
            return false;

        }

        bool hasPath(int src,int dst){
            vector<bool> visited(this->vertex,false);
            for(vw i:adjList[src]){
                if(!visited[i.vertex]){
                    visited[i.vertex] = true;
                    if(_hasPath(i.vertex,dst,visited))
                        return true;
                }
            }
            return false;
        }
};
int main(){
    int vertex = 6;
    graph g(vertex);
    g.addEdge(0,1,10);
    g.addEdge(0,4,10);
    g.addEdge(4,5,10);
    g.addEdge(1,2,10);
    g.addEdge(2,3,10);
    g.addEdge(3,1,10);
    g.diplayGraph();
    cout << g.hasPath(0,3) << endl;
    return 0;
}