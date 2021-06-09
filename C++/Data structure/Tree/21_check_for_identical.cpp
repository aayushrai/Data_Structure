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

bool isIdentical(node* root1,node* root2){
    if(!root1 and !root2)
        return true;
    if((!root1 or !root2))
        return false;
    if(root1->val == root2->val)
        return isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right);   
    return false;
}
int main(){

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(5);
    root2->left->right = new node(3);
    root2->left->right->left = new node(4);
    root2->right->left = new node(8);
    root2->right->left->left = new node(10);
    root2->right->right = new node(6);
    root2->right->right->left = new node(7);
    root2->right->right->left->left = new node(9);

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->right = new node(3);
    root->left->right->left = new node(4);
    root->right->left = new node(8);
    root->right->left->left = new node(10);
    root->right->right = new node(6);
    root->right->right->left = new node(7);
    root->right->right->left->left = new node(9);

    cout << isIdentical(root,root2);
    
    return 0;
}