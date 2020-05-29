#include<iostream>
#include<vector>
using namespace std;
int SOS(int,int);
int arr[200],n,k;
int counter =0;
int main(){
    cout << "Enter number of item: ";
    cin >> n;
    cout << "Enter items: ";
    for(int i=0;i<n;i++)
       cin >> arr[i];
    cout << "Enter val of k: ";
    cin >> k;
    bool b = SOS(0,n-1);
    if(b)
      cout << "Sum of subset is equal k"<<endl;
    else
      cout << "Sum of subset is not equal k"<<endl;
    return 0;
}

int SOS(int temp,int n){
   if((temp+arr[n])>k or n<0){
       return false;
   }
   if((temp+arr[n])== k){

       return true;
   }
    return SOS(temp,n-1) or SOS(temp+arr[n],n-1);
}