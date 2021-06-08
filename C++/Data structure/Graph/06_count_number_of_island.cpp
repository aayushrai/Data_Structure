#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void removeConnectedIsland(int i,int j,vector<vector<int>>& mp){
    if(i<0 or j<0 or i>=mp.size() or j>=mp[0].size() or mp[i][j]!=1)
        return;
    mp[i][j] = 0;
    removeConnectedIsland(i+1,j,mp);
    removeConnectedIsland(i-1,j,mp);
    removeConnectedIsland(i,j+1,mp);
    removeConnectedIsland(i,j-1,mp);
    removeConnectedIsland(i-1,j-1,mp);
    removeConnectedIsland(i+1,j+1,mp);
    removeConnectedIsland(i+1,j-1,mp);
    removeConnectedIsland(i-1,j+1,mp);
}

int main(){
   
    vector<vector<int>> mp =  {
        { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
    };
    //  1 is island
    //  0 is water
    //  count number of island
    int vertex = mp.size();
    int island = 0;
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            if(mp[i][j]==1){
                removeConnectedIsland(i,j,mp);
                island++;
            }
                
        }
    }
   
    cout << island << endl;
    return 0;
}