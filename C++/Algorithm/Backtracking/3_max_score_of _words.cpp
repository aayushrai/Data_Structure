#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> src;
    vector<string> wrd;
    int msw(int i,  vector<int> let){
        if(i<0)
            return 0;
        int sc = 0;
        vector<int> let2;
        let2 = let;
        for(int j=0;j<wrd[i].length();j++){
            if(let2[wrd[i][j]-'a']<=0){
                return msw(i-1,let);
            }
            else{
                sc += src[wrd[i][j]-'a'];
                let2[wrd[i][j]-'a']--;
            }
        }
        return(max(msw(i-1,let2)+sc,msw(i-1,let)));
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> let(26,0);
        src = score;
        wrd = words;
        for(int i=0;i<letters.size();i++){
            let[letters[i]-'a'] += 1;
        }
         return msw(words.size()-1,let);
    }
};


int main(){
    vector<string> words;
    vector<int> score;
    vector<char>letters;
    words = {"dog","cat","dad","good"};
    letters = {'a','a','c','d','d','d','g','o','o'};
    score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    Solution obj;
    cout << obj.maxScoreWords(words,letters,score) << endl;
    return 0 ;
}