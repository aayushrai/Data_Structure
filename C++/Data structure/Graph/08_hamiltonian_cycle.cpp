#include<bits/stdc++.h>

using namespace std;

class graph{
    int vertex;
    vector<vector<int>> adjList;
    public:
    graph(int vertex){
        this->vertex = vertex;
        this->adjList.resize(vertex,vector<int>());
    }
    void addEdge(int s,int d){
        adjList[s].push_back(d);
        adjList[d].push_back(s);
    }
    
    void hamiltonianCycle(int src,int visited_count,vector<bool>& visited,vector<int>& path,int origin){
        visited_count+=1;
        visited[src] = true;
        path.push_back(src);
        if(visited_count == this->vertex){
            for(int v:path){
                cout << v << " ";
            }
            //  if any vertex of last element of path is origin then it's hamiltonian cycle
            for(int vv:this->adjList[path[path.size()-1]]){
                if(vv == origin){
                    cout << " <-- hamiltonian cycle ";
                    break; 
                }
            }
            cout << endl;
        }
        for(int v:this->adjList[src]){
            if(!visited[v])
                hamiltonianCycle(v,visited_count,visited,path,origin);
        }
        visited[src] = false;
        path.pop_back();

    }

};

int main(){
    int vertex = 7;
    graph G(vertex);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(1,4);
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(4,5);
    G.addEdge(4,6);
    G.addEdge(5,6);
    vector<bool> visited(vertex,false);
    vector<int> path = {};
    int start = 0;
    G.hamiltonianCycle(start,0,visited,path,start);
}

// 0 ---- 1 --- 4  
// |      |     |  \    
// 3 ---- 2 --- 5---6
