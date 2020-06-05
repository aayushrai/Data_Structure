#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    vector<int> v{1,3,6};
    cout << upper_bound(v.begin(),v.end(),1)-v.begin();
    return 0;
}



