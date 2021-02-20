#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100],n;
    cin >> n;
    vector<int> stockSpan(n,0);
    stack<int> s;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            stockSpan[i] = 1;
        }
        else
        {
            while(not s.empty() and arr[s.top()]<=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                stockSpan[i] = i;
            }
            else if(arr[s.top()]>arr[i])
            {
                stockSpan[i] = i-s.top();
            }
            
        }
        
        s.push(i);
    }
    for(int i =0;i<n;i++)
    {
        cout << stockSpan[i]<<" ";
    }

    return 0;
}