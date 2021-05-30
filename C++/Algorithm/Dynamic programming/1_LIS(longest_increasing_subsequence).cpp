#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[] ={10,12,9,33,21,50,41,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[n] = {0};
    dp[0] = 1;
    for(int i =1;i<n;i++){
        int j = 0;
        while(j<i){
            if(arr[j]< arr[i] and dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
            }
            j++;
        }
    }
    int mx = 0;
    cout << "DP:";
    for(int i =0;i<n;i++){
        cout << dp[i] << " ";
        if(dp[i]>mx)
            mx = dp[i];
    }
    cout << "\n" << "LIS:"<< mx << endl;

    return 0;
}