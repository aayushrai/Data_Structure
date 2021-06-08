#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct doll{
    int h,w;
};

bool compare(struct doll a,struct doll b){
    if(a.h==b.h)
        return a.w > b.w;
    return a.h < b.h;

}

int lis(struct doll arr[],int n){
    int dp[n]={0};
    dp[0] = 1;
    int mx = 0;
    for(int i=1;i<n;i++){
        dp[i]=1;
        int j = 0;
        while(j<i){
            if(arr[j].w < arr[i].w and dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                if(dp[i] > mx)
                    mx = dp[i];
            }
            j++;
        }
    }
    return mx;
}


int main(){
    struct doll arr[] = {{17,5},{26,18},{25,34},{48,84},{63,72},{42,86},{9,55},{4,70},{21,45},{68,76},{58,51}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,compare);
    cout << lis(arr,n);
    return 0;
}