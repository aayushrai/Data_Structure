#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[] ={10,12,9,33,21,50,41,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[n] = {0};
    int mx = 1;
    for(int i =0;i<n;i++){
        dp[i] = 1;
        int j = 0;
        while(j<i){
            if(arr[j]< arr[i] and dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                if(dp[i]>mx)
                    mx = dp[i];
            }
            j++;
        }
    }
    cout << "LIS:"<< mx << endl;

    cout << "DP:";
    for(int i =0;i<n;i++){
        cout << dp[i] << " ";
    }

    return 0;
}