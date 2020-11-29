
#include<iostream>
using namespace std;
int heap[] = {43,43,434,3436,87,675,487,45,65};
int n = 9;
int k =5;

void maxHeapify(int i,int n){
    int largest,left,right;
    largest = i;
    left = (2*i)+1;
    right = (2*i)+2;
    if(left<n and heap[left]>heap[largest])
        largest = left;
    if(right<n and heap[right]>heap[largest])
        largest  = right;
    if(largest != i){
        int temp = heap[largest];
        heap[largest] = heap[i];
        heap[i] = temp;
    }
    
}

int main(){
    for(int m =int(k/2)-1;m>=0;m--)
        maxHeapify(m,k);
    
    for(int l=k;l<n;l++){
        if(heap[l]<heap[0]){
            int temp = heap[l];
            heap[l] = heap[0];
            heap[0] = temp;
            for(int m =int(k/2)-1;m>=0;m--)
                maxHeapify(m,k);
        }
    }
    for(int j =0;j<n;j++)
        cout << heap[j] << " ";
    
    return 0;
}


    



