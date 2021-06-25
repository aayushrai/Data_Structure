#include<iostream>
#include<bits/stdc++.h>

using namespace std;



//    ""  a  b  c  c  d
// "" 0   0  0  0  0  0
// a  0   1  1  1  1  1
// b  0   1  2  2  2  2  
// e  0   1  2  2  2  2
// d  0   1  2  2  2  3   <- lcs

int main(){
    string a = "ababasd";
    string b = "abassvabasd";
    int n = a.length();
    int m = b.length();
    int dp[n+1][m+1]={0};
    // memset(dp,0,sizeof(dp));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0  or j==0)
                dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << "length of lcs:" << dp[n][m] << endl;
    string lcs = "";
    while(m>0 and n>0){
        if(a[n-1]==b[m-1]){
            lcs = a[n-1]+lcs;
            m--;
            n--;
        
        }
        else if(dp[n-1][m]>dp[n][m-1])
            n--;
        else
            m--;
    }
    cout << lcs << endl;
}