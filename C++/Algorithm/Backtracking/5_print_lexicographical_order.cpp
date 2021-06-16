#include<bits/stdc++.h>

using namespace std;

void printLexicographicalOrder(int n,int output){
    if(output>n )
        return;
    cout << output << endl;
    for(int i=0;i<=9;i++){
        if(output == 0 and i==0 ){
            continue;
        }
        printLexicographicalOrder(n,10*output + i);
    }
}

int main(){
    int n=1000;
    printLexicographicalOrder(n,0);
}

