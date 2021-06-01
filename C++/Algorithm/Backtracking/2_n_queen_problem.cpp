#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>>board;
bool check(int i,int j){
    for(int k=j-1;k>=0;k--){
        if(board[i][k]==1)
            return false;
    }
    for(int k=1;k<=j;k++){
            if(i-k >= 0 and j-k >= 0 and board[i-k][j-k]==1)
                return false;
    }
      for(int k=1;k<=j;k++){
            if(i+k < n and j-k >=0 and board[i+k][j-k]==1)
                return false;
    }
    return true;
}
bool NQ(int j){
    if(j>=n){
        return true;
    }
    for(int l=0;l<n;l++){
        if(check(l,j)){
            board[l][j] = 1;
            if(NQ(j+1))
                return true;
            board[l][j] = 0;
        }
    }
  return false;

}

int main(){
    n = 10;
    vector<vector<int>> arr(n,vector<int>(n,0));
    board = arr;
    NQ(0);
    for(int i =0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}