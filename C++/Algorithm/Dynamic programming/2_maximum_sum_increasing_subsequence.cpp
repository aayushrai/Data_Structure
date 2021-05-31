#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main(){
    int arr[] = {2,1,4,2,5,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[n] ={0};
    int mx = 0;
    for(int i=0;i<n;i++){
        dp[i] = arr[i];
        int j = 0;
        while(j<i){
            if(arr[j]<arr[i] and dp[i]<dp[j]+arr[i]){
                dp[i] = dp[j]+arr[i];
                if(dp[i]>mx)
                    mx = dp[i];
                
            }
            j++;
        }
    }
    cout << "MSIS:"<< mx << endl;

//--------------------------------------------------------------------------------------------------------------------------------------------
    cout << "DP:";
    for(int i =0;i<n;i++){
        cout << dp[i] << " ";
    }
    return 0;
}