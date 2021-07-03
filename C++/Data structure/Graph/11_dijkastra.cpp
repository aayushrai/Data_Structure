#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pr;
#define mk(a,b) make_pair(a,b)
// typedef struct cost_vertex_path{
//     int cost;
//     int vertex;
//     string path;
    
// }cvp;
class graph{
    public:
        int vertex;
        vector<vector<pr>> adjList;
        graph(int vertex){
            this->vertex = vertex;
            adjList.resize(vertex,vector<pr>());
        }

        void addEdge(int src,int dst,int wg){
            adjList[src].push_back(mk(dst,wg));
            adjList[dst].push_back(mk(src,wg));
        }
        // shortest path in weighted graph
        void dijkastra(int src){
            priority_queue<pr,vector<pr>,greater<pr>> minHeap;
            pr temp = {0,src};
            minHeap.push(temp);
            vector<bool> relaxedVertex(vertex,false);
            while(!minHeap.empty()){
                pr temp = minHeap.top();
                minHeap.pop();
                if(relaxedVertex[temp.second])
                    continue;
                relaxedVertex[temp.second] = true;
                cout << temp.second << " " << temp.first << endl;
                for(pr vc:adjList[temp.second]){
                    if(!relaxedVertex[vc.first]){
                        pr ngb = {vc.second+temp.first,vc.first};
                        minHeap.push(ngb);
                    }
                }
            }

        }
};

int main(){
    int vertex = 6;
    graph g(vertex);
    g.addEdge(0,1,2);
    g.addEdge(1,2,9);
    g.addEdge(0,2,4);
    g.dijkastra(0);
}