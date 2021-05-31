#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node* left;
    node* right ;

    node(int val){
        this->val = val;
        left =right = NULL;
    }
}node;


void kthNodes(node* root,int k){
    if(not root)
        return;
    if(k==0)
        cout << root->val << " ";
    
    kthNodes(root->left,k-1);
    kthNodes(root->right,k-1);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->right = new node(3);
    root->left->right->left = new node(4);
    root->right->left = new node(8);
    root->right->right = new node(6);
    root->right->right->left = new node(7);
    root->right->right->left->left = new node(9);
    kthNodes(root,2);
   
    return 0;
}

//     1
//   /   \
//  2     5
//   \   / \
//    3 8   6   k == 2(root to node distance is k)
//   /     /
//  4     7
//       /
//      9
//    
// is any root to leaf sum is equal to given sum