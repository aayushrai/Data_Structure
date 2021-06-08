#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct CityPairs{
    int north,south;
};

// Input : 6 4 2 1
//         2 3 6 5
// Output : Maximum number of bridges = 2
// Explanation: Let the north-south x-coordinates
// be written in increasing order.



// output
// 1  2  3  4  5  6   north
//   \  \
//    \  \        For the north-south pairs
//     \  \       (2, 6) and (1, 5)
//      \  \      the bridges can be built.
//       \  \     We can consider other pairs also,
//        \  \    but then only one bridge can be built 
//         \  \   because more than one bridge built will
//          \  \  then cross each other.
//           \  \
// 1  2  3  4  5  6   south
bool compare(struct CityPairs A,struct CityPairs B){
    if(A.north==B.north)
        return A.south < B.south;
    return A.north<B.north;
     
}
// int LIS(int i,int mx,int n,struct CityPairs values[]){
//     if(i>=n)
//         return 0;
//     if(values[i].south > mx){
//         return max(LIS(i+1,values[i].south,n,values)+1,LIS(i+1,mx,n,values));
//     }
//     return LIS(i+1,mx,n,values);

// }
int LIS(struct CityPairs values[],int n){
    vector<int> dp(n,0);
    int mx = 0;
    dp[0] = 1;
    for(int i=1;i<n;i++){
        int j = 0;
        dp[i] = 1;
        while(j<i){
            if(values[j].south < values[i].south and dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
                if(dp[i] > mx)
                    mx = dp[i];
            }
            j++;
        }
    }
    return mx;
}
int maxBridges(struct CityPairs values[],int n){
    if(n==0)
        return 0;
    sort(values,values+n,compare);
    return LIS(values,n);
}

int main(){
  
    // struct CityPairs values[] = {{6,2},{4,3},{2,6},{1,5}}; 
    struct CityPairs values[] = {{8,1},{1,2},{4,3},{3,4},{5,5},{2,6},{6,7},{7,8}};
    int n = sizeof(values)/sizeof(values[0]);
    cout << "Maximum number of bridges = " << maxBridges(values, n) << endl; 
    return 0;
}