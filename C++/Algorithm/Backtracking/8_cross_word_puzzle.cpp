    // #include<bits/stdc++.h>

    // using namespace std;


    // bool isHorizontalFix(vector<string>& puzzle,string word,int x,int y){
    //     if(y-1>=0 and puzzle[x][y-1]!='+')
    //         return false;
    //     if(y+word.length()<puzzle[x].length() and puzzle[x][y+word.length()]!='+')
    //         return false;
    //     for(int i=0;i<word.length();i++){
    //         if(puzzle[x][y+i]!='-' and puzzle[x][y+i]!=word[i] )
    //             return false;   
    //     }
    //     return true;
    // }

    // bool isVerticalFix(vector<string>& puzzle,string word,int x,int y){
    //     if(x-1>=0 and puzzle[x-1][y]!='+')
    //         return false;
    //     if(x+word.length()<puzzle[y].length() and puzzle[x+word.length()][y]!='+')
    //         return false;
    //     for(int i=0;i<word.length();i++){
    //         if(puzzle[x+i][y]!='-' and puzzle[x+i][y]!=word[i] )
    //             return false;   
    //     }
    //     return true;
    // }

    // vector<bool> fixHorizontal(vector<string>& puzzle,string word,int x,int y){
    //     vector<bool> FixByUs(word.size(),false);
    //     for(int i=0;i<word.length();i++){
    //         if(puzzle[x][y+i]=='-'){
    //             puzzle[x][y+i] = word[i]; 
    //             FixByUs[i] = true;    
    //         }
    //     }
    //     return FixByUs;
    // }

    // vector<bool> fixVertical(vector<string>& puzzle,string word,int x,int y){
    //     vector<bool> FixByUs(word.size(),false);
    //     for(int i=0;i<word.length();i++){
    //         if(puzzle[x+i][y]=='-'){
    //             puzzle[x+i][y] = word[i]; 
    //             FixByUs[i] = true;    
    //         }
    //     }
    //     return FixByUs;
    // }
    // void unfixVertical(vector<string>& puzzle,vector<bool>FixByUs,int x,int y){
    //     for(int i=0;i<FixByUs.size();i++){
    //         if(FixByUs[i]){
    //             puzzle[x+i][y] = '-'; 
    //         }
    //     }
    // }

    // void unfixHorizontal(vector<string>& puzzle,vector<bool>FixByUs,int x,int y){
    //     for(int i=0;i<FixByUs.size();i++){
    //         if(FixByUs[i]){
    //             puzzle[x][y+i] = '-'; 
    //         }
    //     }
    // }

    // void solve(vector<string>& puzzle,vector<string>words,int wIndex){
    //     if(wIndex==words.size()){
    //          for(int i=0;i<puzzle.size();i++){
    //         for(int j=0;j<puzzle[0].length();j++){
    //             cout << puzzle[i][j] << " ";
    //         }
    //         cout << endl;
    //         }
    //         return;
    //     }

    //     for(int i=0;i<puzzle.size();i++){
    //         for(int j=0;j<puzzle[0].length();j++){
    //             if(puzzle[i][j]=='-' or words[wIndex][0]==puzzle[i][j]){
    //                     if(isHorizontalFix(puzzle,words[wIndex],i,j)){
    //                         vector<bool> FixByUs = fixHorizontal(puzzle,words[wIndex],i,j);
    //                         solve(puzzle,words,wIndex+1);
    //                         unfixHorizontal(puzzle,FixByUs,i,j);
    //                     }
    //                     else if(isVerticalFix(puzzle,words[wIndex],i,j)){
    //                         vector<bool> FixByUs =fixVertical(puzzle,words[wIndex],i,j);
    //                         solve(puzzle,words,wIndex+1);
    //                         unfixVertical(puzzle,FixByUs,i,j);
    //                     }
    //             }
    //         }
    //     }
        
    // }

    // int main(){
    //     vector<string> puzzle = {
    //         "+-++++++++",
    //         "+-++++++++",
    //         "+-++++++++",
    //         "+-----++++",
    //         "+-+++-++++",
    //         "+-+++-++++",
    //         "+++++-++++",
    //         "++------++",
    //         "+++++-++++",
    //         "+++++-++++",
    //     };
    //     vector<string> words = {
    //         "LONDON",
    //         "DELHI" ,
    //         "ICELAND", 
    //         "ANKARA",
    //     };
    //     solve(puzzle,words,0);
    // }


// ============================================================================================================
// Approach 2 Just pass the copy of puzzle( means don't pass by refernce in solve function)

    #include<bits/stdc++.h>

    using namespace std;


    bool isHorizontalFix(vector<string>& puzzle,string word,int x,int y){
        if(y-1>=0 and puzzle[x][y-1]!='+')
            return false;
        if(y+word.length()<puzzle[x].length() and puzzle[x][y+word.length()]!='+')
            return false;
        for(int i=0;i<word.length();i++){
            if(puzzle[x][y+i]!='-' and puzzle[x][y+i]!=word[i] )
                return false;   
        }
        return true;
    }

    bool isVerticalFix(vector<string>& puzzle,string word,int x,int y){
        if(x-1>=0 and puzzle[x-1][y]!='+')
            return false;
        if(x+word.length()<puzzle[y].length() and puzzle[x+word.length()][y]!='+')
            return false;
        for(int i=0;i<word.length();i++){
            if(puzzle[x+i][y]!='-' and puzzle[x+i][y]!=word[i] )
                return false;   
        }
        return true;
    }

    void fixHorizontal(vector<string>& puzzle,string word,int x,int y){
        for(int i=0;i<word.length();i++){
            if(puzzle[x][y+i]=='-'){
                puzzle[x][y+i] = word[i];  
            }
        }
    }

    void fixVertical(vector<string>& puzzle,string word,int x,int y){
        for(int i=0;i<word.length();i++){
            if(puzzle[x+i][y]=='-'){
                puzzle[x+i][y] = word[i];  
            }
        }
    }

    void solve(vector<string>& puzzle,vector<string>words,int wIndex){
        if(wIndex==words.size()){
             for(int i=0;i<puzzle.size();i++){
            for(int j=0;j<puzzle[0].length();j++){
                cout << puzzle[i][j] << " ";
            }
            cout << endl;
            }
            return;
        }

        for(int i=0;i<puzzle.size();i++){
            for(int j=0;j<puzzle[0].length();j++){
                if(puzzle[i][j]=='-' or words[wIndex][0]==puzzle[i][j]){
                        if(isHorizontalFix(puzzle,words[wIndex],i,j)){
                           fixHorizontal(puzzle,words[wIndex],i,j);
                            solve(puzzle,words,wIndex+1);                 
                        }
                        else if(isVerticalFix(puzzle,words[wIndex],i,j)){
                            fixVertical(puzzle,words[wIndex],i,j);
                            solve(puzzle,words,wIndex+1);
                        }
                }
            }
        }
        
    }

    int main(){
        vector<string> puzzle = {
            "+-++++++++",
            "+-++++++++",
            "+-++++++++",
            "+-----++++",
            "+-+++-++++",
            "+-+++-++++",
            "+++++-++++",
            "++------++",
            "+++++-++++",
            "+++++-++++",
        };
        vector<string> words = {
            "LONDON",
            "DELHI" ,
            "ICELAND", 
            "ANKARA",
        };
        solve(puzzle,words,0);
    }


