#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node* left;
    node* right;

    node(int val){
        this->val = val;
        left = right = NULL;
    }
}node;


int sumTree(node* root,bool &isSumTree){
    if(!root)
        return 0;
    if(!root->left and !root->right){
        return root->val;
    }
    int left = sumTree(root->left,isSumTree);
    int right = sumTree(root->right,isSumTree);

    if(left+right != root->val)
        isSumTree = false;
    return left+right+root->val;
}


int main(){
    node* root = new node(20);
    root->left = new node(3);
    root->right = new node(7);
    root->right->left = new node(3);
    root->right->right = new node(4);
    root->left->left = new node(2);
    root->left->right = new node(1);
    bool isSumTree = true;
    sumTree(root,isSumTree);
    cout << isSumTree << endl;
    return 0;
}


  /*   sum tree
         20 (1+2+3+4+3+7)
       /   \  
(1+2) 3     7  (4+3) 
    / \     / \  
   1   2   4   3 
    */