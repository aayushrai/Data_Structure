#include<iostream>
using namespace std;
// int max(int a, int b) { return (a > b) ? a : b; } 
  


int main()
{
    int weights[100],price[100],cap,n;
    cout << "Enter number of Items : ";
    cin >> n;
    cout << "Enter Weights: ";
    for(int i=0;i<n;i++)
         cin >> weights[i];
    cout << "Enter Price: ";
    for(int j=0;j<n;j++)
         cin >> price[j];
    cout << "Enter Capacity : ";
    cin >> cap;
    int dp[100][100];
    for(int i=0;i<=n;i++){
    for(int j=0;j<=cap;j++){
        if(i == 0 || j ==0)
            dp[i][j] = 0;
        else if (weights[i - 1] <= j) 
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i-1]]+price[i-1]);
        else
            dp[i][j] = dp[i-1][j]; 
           
    }}
  cout << dp[n][cap];
}
   
