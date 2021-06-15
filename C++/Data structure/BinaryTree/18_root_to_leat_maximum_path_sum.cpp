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


int rootToLeafNodesPathMaxSum(node* root){
    if(not root)
        return 0;
    if(!root->left and !root->right){
        return root->val;
    }
    return(max(rootToLeafNodesPathMaxSum(root->left)+root->val,rootToLeafNodesPathMaxSum(root->right)+root->val));
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
    cout << rootToLeafNodesPathMaxSum(root);
   
    return 0;
}

//     1
//   /   \
//  2     5
//   \   / \
//    3 8   6
//   / (14)/
//  4     7
// (10)  /
//      9
//     (28)
// maximum sum from root to leaf