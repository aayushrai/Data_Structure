#include <bits/stdc++.h>
using namespace std;
typedef vector<int> pr;
#define f(i,a,b) for(int i=a;i<b;i++)
// main program
int main() {
   priority_queue<pr> priorityq;
   int minmarks,students,assingm;
   vector<int> marks;
   cin >> minmarks >> students >> assingm;
   f(i,0,students){
       int temp;
       cin >> temp;
       marks.push_back(temp); 
   }
   int c = 0;
   f(i,0,assingm){
       int score,subpart;
       cin >> score >> subpart;
       priorityq.push({subpart,-score,c});
       c += 1;
   }
   bool flag = false;
   vector<vector<int>> ans(students,vector<int>(assingm,0));
   while(!flag and !priorityq.empty()){
       pr top = priorityq.top();
       priorityq.pop();
       flag = true;
       f(i,0,students){
           if(marks[i] < minmarks){
                marks[i] -= top[1];
                ans[i][top[2]] = 1;
                flag = false;
           }
       }
       
   }
   f(i,0,students){
       int c = 0;
       f(j,0,ans[i].size()){
           if(ans[i][j] == 1)
                c+=1;
       }
        cout << c << " ";
       f(j,0,ans[i].size()){
           if(ans[i][j] == 1)
                cout << j+1 << " ";  
       }
       cout << endl;
   }
 
  
  
   return 0;
}