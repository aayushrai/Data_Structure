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

int height(node* root){
    if(not root)
        return 0;
    return 1 + max(height(root->left),height(root->right));
}

int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(7);
    root->left->right = new node(3);
    root->right->left = new node(2);
    root->right->right = new node(5);
    root->right->right->left = new node(5);
    cout <<"height of tree is "<< height(root);
    return 0;
}


