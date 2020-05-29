#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  char s1[100],s2[100];
  int dp[100][100];
  int counter = 0;
  cout << "Enter First String: ";
  cin.getline(s1,100);
  cout << "Enter Second String: ";
  cin.getline(s2,100);
  for(int i=0;i<=strlen(s1);i++){
      for(int j=0;j<=strlen(s2);j++){
          if(i == 0 || j ==0){
            dp[i][j] = 0;
          }
          else if(s1[i-1] == s2[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
            counter += 1;
          }
          else{
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            counter += 1;
          }
      }
     
  }
  int i =strlen(s1),j = strlen(s1);
  int lcsLen = dp[strlen(s1)][strlen(s2)];
  int index = lcsLen;
  char res[lcsLen+1];
  res[index] = '\0';
  while(i>0 and j >0)
  {
    if(s1[i-1] == s2[j-1]){
          res[index-1] = s1[i-1];
          index -= 1;
          i -= 1;
          j -= 1;
    }
    else if(dp[i-1][j]>dp[i][j-1])
       i -= 1;
    else
       j -= 1;
  }
 cout << "Length Longest Common Subsequence : "<< lcsLen<<endl;
 cout << "Longest Common Subsequence : "<< res <<endl;
 cout << "Number of Common Subsequence : "<< counter <<endl;
}