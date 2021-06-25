/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int j,arr[]={6,2,5,4,5,1,6},n=7;
   vector<int> nsl(n,0);
   vector<int> nsr(n,0);
   stack<int> s1;
   stack<int> s2;
   for(int i=0;i<n;i++){
       while(not s1.empty() and arr[s1.top()]>=arr[i]){
           s1.pop();
       }
       if(s1.empty()){
           nsl[i] = -1;
       }
       else if(arr[s1.top()]<arr[i]){
           nsl[i] = s1.top();
       }
       s1.push(i);
       j = n-i-1;
       
       while(not s2.empty() and arr[s2.top()]>=arr[j]){
           s2.pop();
       }
       if(s2.empty()){
           nsr[j] = -1;
       }
       else if(arr[s2.top()]<arr[j]){
           nsr[j] = s2.top();
       }
       s2.push(j);
   } 
   for(int k=0;k<n;k++){
       cout << nsl[k] << " ";
   }
   cout << "\n";
     for(int k=0;k<n;k++){
       cout << nsr[k] << " ";
   }
   cout << "\n";
   int maximum_area_hist = 0;
    for(int k=0;k<n;k++){
       int temp = (nsr[k]-nsl[k]-1)*arr[k] ;
       if(maximum_area_hist>temp)
            maximum_area_hist = temp;
    }
    cout << "\n";
   cout << "maximum_area_hist = " << maximum_area_hist;
    return 0;
}
