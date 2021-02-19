#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int arr[100];
    stack<int> s;
    int n;
    cin >> n;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=n-1;i>=0;i--){
        while(not s.empty() and s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else if(s.top()>arr[i]){
            ans[i] = s.top(); 
        }
        s.push(arr[i]);
    }
    cout << "Output:"
    for(int i=0;i<n;i++){
        cout  << ans[i] << " ";
    }

    return 0;
}
