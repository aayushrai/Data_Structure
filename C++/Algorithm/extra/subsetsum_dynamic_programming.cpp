#include<iostream>
#include<vector>
using namespace std;
int arr[200],n,k;

bool SOS(int sett[], int n, int sum)
{
    bool subset[n+1][sum+1];

    for(int i = 0; i <= n; i++)
    {
        subset[i][0] = true;
        
    }
    for(int i = 1; i <= sum ; i++)
    {
        subset[0][i] = false;
    }
    for(int i = 1; i<=n ; i++)
        {for(int j= 1; j<=sum ; j++)
        {
            if(j < sett[i-1])
                subset[i][j] = subset[i-1][j];
            if(j>= sett[i-1])
                subset[i][j] = subset[i-1][j-sett[i-1]] || subset[i-1][j];
        }
    }
    for(int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }
    return subset[n][sum];
}

int main(){
    cout << "Enter number of element in subsets: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++)
       cin >> arr[i];
    cout << "Enter val of k: ";
    cin >> k;
    bool b = SOS(arr,n,k);
    if(b)
      cout << "Sum of subset is equal k"<<endl;
    else
      cout << "Sum of subset is not equal k"<<endl;
     cout << "Number of sum of subset is equal k "<< counter <<endl;
    return 0;
}

