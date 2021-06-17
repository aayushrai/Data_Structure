#include<bits/stdc++.h>
using namespace std;


void find(int i,string ans,string& digits,unordered_map<char,string> mp,vector<string>& rst){
    if(i>=digits.length()){
        rst.push_back(ans);
        return;
    }
    for(int j=0;j<mp[digits[i]].length();j++){
        find(i+1,ans+mp[digits[i]][j],digits,mp,rst);
    }
        // 
}

void letterCombinations(string digits) {
    vector<string> rst;
    unordered_map<char,string> mp = {{'2',"abc"},{'3',"def",},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    find(0,"",digits,mp,rst);
    for(int i=0;i<rst.size();i++){
        cout << rst[i] << " ";
    }
}

int main(){
    letterCombinations("23");
}