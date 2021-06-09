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

bool mirror(node* root1,node* root2){
    if(!root1 and !root2)
        return true;
    if(!root1 or !root2){
        return false;
    }
    if(root1->val==root2->val){
        return mirror(root1->left,root2->right) and mirror(root1->right,root2->left);
    }
    return false;
}
bool symmteric(node* root){
    if(!root)
        return true;
    return mirror(root->left,root->right);
}

int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->right = new node(1);
    root->right->left = new node(3);
    root->right->right = new node(4);
    root->left->left = new node(4);
    root->left->right = new node(3);
    cout << symmteric(root) << endl;
    return 0;   
}


  /*  Symmetric tree 
      mirror
         0     
       / | \  
      1  |  1   
    / \  |  / \  
   4   3 | 3   4 
    */