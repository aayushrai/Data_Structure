// given string example "pep"

// abbreviations of "pep" are following
// 1 -> replace with 1
// 0 -> do not replace
// if 1 come continusly add them all
// pep 000
// pe1 001
// p1p 010
// p2  011
// 1ep 100
// 1e1 101
// 2p  110
// 3   111

                                           
    //                 ""                 <- start with empty string(input)
    //               /   \                p -> left side replace p with 1 and right side do not replace p
    //          1              p          
    //         / \            /  \        e -> left side replace e with 1 and right side do not replace e
    //        2   1e        p1     pe       
    //       / \   / \     / \    / \     p -> left side replace p with 1 and right side do not replace p
    //      3 2p 1e1 1ep  p2 p1p pe1 pep   <-- output 


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
string s;
void Printabbrevations(int i,string output,int prev){
    if(i>=s.length()){
        cout << output << endl;
        return;
    }

    Printabbrevations(i+1,output+s[i],0);
    if(prev == 0){
        output += to_string(1);
    }
    else{
        output = output.substr(0,output.length()-1) + to_string(prev+1);
    }
    Printabbrevations(i+1,output,prev+1); 
    

}

int main(){
    s = "pep";
    Printabbrevations(0,"",0);
    return 0;
}