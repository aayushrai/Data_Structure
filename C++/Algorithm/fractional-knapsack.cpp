# include<iostream>
using namespace std;
void knapsack(int n, float weight[], float profit[], float capacity)
{
 
   float x[100], tp = 0;
   int i, j, u;
   u = capacity;
   for (i = 0; i < n; i++)
       x[i] = 0.0;
   for (i = 0; i < n; i++)
   {
       if (weight[i] > u)
           break;
       else 
       {
           x[i] = 1.0;
           tp = tp + profit[i];
           u = u - weight[i];
        }
    }
    if (i < n)
         x[i] = u / weight[i];
    tp = tp + (x[i] * profit[i]);
    cout <<"\nMaximum price is :" << tp<<endl;
}
int main()
{
 
   float weight[100], price[100], cap;
   float ratio[20], temp;
   int n;
   cout << "Enter number of Items : ";
    cin >> n;
    cout << "Enter Weights: ";
    for(int i=0;i<n;i++)
         cin >> weight[i];
    cout << "Enter Price: ";
    for(int j=0;j<n;j++)
         cin >> price[j];
    cout << "Enter Capacity : ";
    cin >> cap; 
   for (int i = 0; i < n; i++)
   {
       ratio[i] = price[i] / weight[i];
   }
   for (int i = 0; i < n; i++)
   {
 
      for (int j = i + 1; j < n; j++)
      {
 
         if (ratio[i] < ratio[j])
         {
 
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
            temp = price[j];
            price[j] = price[i];
            price[i] = temp;
 
         }
       }
    }
   knapsack(n, weight, price, cap);
   return(0);
}