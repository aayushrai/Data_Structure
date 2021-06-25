// #define N 5 
#include <stdbool.h> 
#include <stdio.h> 
  
bool isSafe(int board[10][10], int row, int col,int N){ 
    int i, j; 
    for(i = 0; i < col; i++) 
        if(board[row][i]) 
            return false; 
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if(board[i][j]) 
            return false; 
    for(i = row, j = col; j >= 0 && i < N; i++, j--) 
        if(board[i][j]) 
            return false; 
    return true; 
} 

bool NQ(int board[10][10], int col,int N){ 
    if(col >= N) 
        return true; 
    for(int i = 0; i < N; i++) { 
        if(isSafe(board, i, col,N)) { 
            board[i][col] = 1; 
            if(NQ(board, col + 1,N)) 
                return true; 
            board[i][col] = 0; 
        } 
    } 
    return false; 
} 
  
int main(){ 
    int N;
    scanf("%d",&N);
    int board[N][N] = {};
    if(NQ(board, 0,N) == false)
        printf("Solution does not exist");
    for(int i = 0; i < N; i++) { 
        for(int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
}