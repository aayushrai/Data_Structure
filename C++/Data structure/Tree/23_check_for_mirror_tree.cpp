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

bool mirror(node* root,node* root1){
    if(!root and !root1)
        return true;
    if(!root or !root1)
        return false;
    if(root->val == root1->val)
        return mirror(root->left,root1->right) and mirror(root->right,root1->left);
    return false;
}

int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->right->left = new node(3);
    root->right->right = new node(4);

    node* root1 = new node(0);
    root1->left = new node(2);
    root1->right = new node(1);
    root1->left->right = new node(3);
    root1->left->left = new node(4);
    cout<< mirror(root,root1) << endl;
    return 0;
}

    /*     mirror
        0     |     0
       / \    |    / \
      1   2   |   2   1
         / \  |  / \
        3   4 | 4   3
    */