 #include<bits/stdc++.h>

using namespace std;

void gp(int open,int close,int n,string ans,vector<string>& result){

    if(open>=n and close>=n){
        result.push_back(ans);
        return;
    }
    if(open<n){
    if(open > close){
        gp(open+1,close,n,ans+"(",result);
            gp(open,close+1,n,ans+")",result);
        }
    else{
        gp(open+1,close,n,ans+"(",result); 
    }
    }
    else
    {
            gp(open,close+1,n,ans+")",result);
    }
}


int main(){
    int n = 3;
    vector<string> result;
    gp(0,0,n,"",result);
    for(int i=0;i<result.size();i++) cout << result[i] << endl;
}