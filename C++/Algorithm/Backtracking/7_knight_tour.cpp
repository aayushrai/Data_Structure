#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> result;
int n;


void display(vector<vector<int>> board){
      for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
      }
      cout << endl;
}

int knightTour(int x,int y,int count,vector<vector<int>>& board,int move[2][8]){
    if(x<0 or y<0 or x>=n or y>=n or board[x][y] != -1)
        return 0;
    board[x][y]=count;
    if(count == (n*n)-1){
         display(board);
        return 1;
    }
        count++;
        for(int i=0;i<8;i++){
            if(knightTour(x + move[0][i],y + move[1][i],count,board,move))
                return 1;  
        }

    board[x][y]=-1;
    return 0;
}

int main(){
    n = 5; 
    int move[2][8] = {{-2,-2,2,2,-1,+1,-1,+1},{1,-1,1,-1,2,2,-2,-2}};
    vector<vector<int>> board(n,vector<int>(n,-1));
    knightTour(0,0,0,board,move);
}