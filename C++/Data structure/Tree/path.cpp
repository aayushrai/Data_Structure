#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<vector<int>> direction;

pair<int,int> coor(int e,int r, int c){
    
     if(e == 0){
        r = r-1;
        c = c;
    }
    if(e == 1){
        r = r-1;
        c = c+1;
    }
    if(e == 2){
        r = r;
        c = c+1;
    }
    if(e == 3){
        r = r+1;
        c = c+1;
    }
    if(e == 4){
        r = r+1;
        c = c;
    }
    if(e == 5){
        r = r+1;
        c = c-1;
    }
    if(e == 6){
        r = r;
        c = c-1;
    }
    if(e == 7){
        r = r-1;
        c = c-1;
    }
   return make_pair(r,c);

}

int path(int r1,int c1,int r2,int c2,int r3,int c3, int r4, int c4){
    if(r1==0 and c1 == 0 and r2==n-1 and c2==0 and r3 == 0 and c3==m-1 and r4 == n-1 and c4 == m-1)
        return 0;
    int rc1 = m * r1 + c1; 
    int rc2 = m * r2 + c2; 
    int rc3 = m * r3 + c3; 
    int rc4 = m * r4 + c4; 
    for(int i =0;i<8;i++){
          for(int j =0;i<8;i++){
                for(int k =0;i<8;i++){
                      for(int l =0;i<8;i++){
                          if(direction[rc1][i] and direction[rc2][j] and direction[rc3][k] and direction[rc4][l]){
                              pair<int,int> t1 = coor(i,r1,c1);
                              pair<int,int> t2 = coor(j,r2,c2);
                              pair<int,int> t3 = coor(k,r3,c3);
                              pair<int,int> t4 = coor(l,r3,c3);
                              path(t1.first,t1.second,t2.first,t2.second,t3.first,t3.second,t4.first,t4.second);
                          }
                      }
                }
          }
          
    }
}

int main() {
    cin >> n >> m >> s;
    for(int i =0;i<n*m;i++){
        vector<int> temp;
          for(int j =0;j<m+1;j++){
              int ele;
              cin >> ele;
              if(j != 0)
                temp.push_back(ele);
          }
          direction.push_back(temp);
    }
    
    // cout << n << " " << m << " "<< s << endl;
    //  for(int i =0;i<n*m;i++){
    //     vector<int> temp;
    //       for(int j =0;j<m;j++){
    //           cout << direction[i][j] << " ";
    //       }
    //     cout << endl;
    // }

}


// 5 8 20
// 1 0 0 1 1 1 0 0 0
// 2 0 0 1 0 1 1 1 0
// 3 0 0 1 1 0 1 1 0
// 4 0 0 0 0 1 1 1 0
// 5 0 0 1 1 1 0 0 0
// 6 0 0 1 1 1 1 1 0
// 7 0 0 1 1 0 1 1 0
// 8 0 0 0 0 1 0 1 0
// 9 1 1 1 0 1 0 0 0
// 10 1 1 0 0 0 1 1 1
// 11 0 1 1 1 0 0 0 0
// 12 1 0 0 0 1 1 1 1
// 13 1 1 0 0 1 0 0 0
// 14 1 1 1 1 0 0 0 1
// 15 0 0 0 0 1 1 1 1
// 16 1 0 0 0 1 0 0 1
// 17 1 1 0 0 1 0 0 0
// 18 0 0 1 1 1 0 0 0
// 19 0 1 1 1 0 1 1 0
// 20 1 0 0 0 1 0 1 1
// 21 1 0 0 0 1 0 0 0
// 22 0 1 1 0 1 0 0 0
// 23 1 0 0 0 0 1 1 1
// 24 1 0 0 0 0 0 0 0
// 25 1 0 0 1 1 0 0 0
// 26 1 1 1 1 0 0 0 0
// 27 0 0 0 0 1 0 1 1
// 28 1 0 0 1 1 0 0 1
// 29 1 0 0 0 1 1 0 0
// 30 1 1 0 1 1 0 0 0
// 31 0 0 1 1 1 1 0 0
// 32 0 0 0 0 1 1 1 0
// 33 1 0 1 0 0 0 0 0
// 34 0 0 0 0 0 0 1 1
// 35 1 0 0 0 0 0 0 1
// 36 1 1 1 0 0 0 0 0
// 37 1 0 0 0 0 0 1 1
// 38 1 1 1 0 0 0 0 0
// 39 1 1 1 0 0 0 1 1
// 40 1 0 0 0 0 0 1 1