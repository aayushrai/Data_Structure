

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
   vector<int> nums;
   int k,n;
   cout << "Enter value of k: ";
   cin >> k;
   cin >> n;
   for(int i=0;i<n;i++){
       cin >> nums[i];
       }
   unordered_map<int,int> hashmap;
   int total = 0,count =0;
   for(int j=0;j<n;j++){
       total += nums[j];
       if(total == k)
       {
           count += 1;
         }
       if(hashmap.find(total-k)!=hashmap.end())
       {
           count += hashmap[total-k];
       }
       hashmap[total] += 1;
           }
    cout <<"count = " << count <<endl;
  return 0;
}