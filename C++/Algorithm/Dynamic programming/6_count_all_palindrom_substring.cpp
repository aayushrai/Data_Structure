
// memoization (top down approach)

// create all the possible substring
// example aba -> a,ab,aba,b,ba,a
// for each string each string is palindrom or not, if palindrom then increament the counter
// the function which checking string ispalindrom we apply memoization in that

// abba -> check for  a__a , -> then we check for _bb_ 
// bb is already checked before for palindrom so we use memoization for that to save time

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;


// vector<vector<int>> dp;
// int isPalindrom(int i,int j,string S,int N){
//     if(i>j)
//         return 1;
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     if(S[i]==S[j])
//         return dp[i][j] = isPalindrom(i+1,j-1,S,N);
//     return dp[i][j]=0;
    
// }

// int CountAllPalindromSubstring(string S, int N)
// {
//     dp.resize(N,vector<int>(N,-1));
//     int count = 0;
//     for(int i=0;i<N;i++){
//         for(int j=i;j<N;j++){
//             cout << i << " " << j << endl;
//             if(isPalindrom(i,j,S,N)){
//                 count++;
//             }
//         }
//     }
//     return count;
    
    
// }

// int main(){
//     string s = "abaab";
//     cout << CountAllPalindromSubstring(s,s.length());
//     return 0;
// }


//--------------------------------------------------------------------------------------------------------------------------------------------------

// tabulation (bottom up approach)

//      a  b  c  b
//   a  T  F  F  F    
//   b  x  T  F  T
//   c  x  x  T  F
//   b  x  x  x  T
//          
//  row 0 col 0 say start from a and end at a
//  row 0 col 1 say start from a and end at b
//  row 1 col 1 say start from b and end at b

//  5  palindrom a,b,c,d,bcb (all the T is table is palindrom)

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


vector<vector<bool>> dp;

int CountAllPalindromSubstring(string S, int N)
{
    dp.resize(N,vector<bool>(N,false));
    int count = 0;
    for(int col=0;col<N;col++){
        for(int start=0,end=col;start<N,end<N;start++,end++){
            //  length 1 palindrom 
            if(start==end){
                dp[start][end] = true;
                count++;
            }
            // length 2 palindrom
            else if(col == 1){
                    if(S[start] == S[end]){
                        dp[start][end] = true;
                        count++;
                    }
                    else{
                        dp[start][end] = false;
                    }
                }
            // length greater then 2
            else if(S[start] == S[end]){
                dp[start][end] = dp[start+1][end-1];
                if(dp[start][end]){
                    count++;
                }
            }
            else if(S[start] != S[end]){
                 dp[start][end] = false;
            }
        }
    }
    return count;
    
    
}

int main(){
    string s = "abbaeae";
    cout << CountAllPalindromSubstring(s,s.length());
    return 0;
}
