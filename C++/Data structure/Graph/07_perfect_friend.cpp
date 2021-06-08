#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
        int vertex;
        vector<vector<int>> adjList;
        graph(int vertex){
            this->vertex=vertex;
            adjList.resize(vertex,vector<int>());
        }
        void addEdge(int src,int dst){
            adjList[src].push_back(dst);
            adjList[dst].push_back(src);
        }
        void dfs(int src,vector<int>& component,vector<bool>& visited){
            visited[src] = true;
            component.push_back(src);
            for(int j:this->adjList[src]){
                if(!visited[j])
                    dfs(j,component,visited);
            }
        }
        
        vector<vector<int>> connectedComponent(){
            vector<vector<int>> components;
            vector<bool> visited(vertex,false);
            for(int i=0;i<vertex;i++){
                if(!visited[i]){
                    vector<int>component={};
                    dfs(i,component,visited);
                    components.push_back(component);
                }
            }
            return components;
        }
};
int main(){
    int vertex = 7;
    graph g(vertex);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(5,6);
    vector<vector<int>> Components;
    Components = g.connectedComponent();
    int ans = 0;
    for(int i=0;i<Components.size();i++){
         for(int j=i+1;j<Components.size();j++){
             ans += Components[i].size() * Components[j].size();
         }
    }
    cout << ans;
    return 0;
}