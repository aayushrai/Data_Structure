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

void leftBoundary(node* root){
    if(not root)
        return;
    if(root->left){
        cout << root->val<< " ";
        leftBoundary(root->left);
    }
    else if(root->right){
        cout << root->val<< " ";
        leftBoundary(root->right);
    }
}

void rightBoundary(node* root){
    if(not root)
        return;
    if(root->right){
        rightBoundary(root->right);
        cout << root->val << " ";
    }
    else if(root->left){
        rightBoundary(root->left);
          cout << root->val<< " ";
    }
}

void leafNodes(node* root){
    if(not root )
        return;
    if(root->left)
        leafNodes(root->left);
    if(root->right)
        leafNodes(root->right);
    if(!root->left and !root->right)
        cout << root->val<< " ";
    
}
void boundaryTraversal(node* root){
    if(not root)
        return;
    cout << root->val << " ";
    leftBoundary(root->left);
    leafNodes(root);
    rightBoundary(root->right);

    
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    // root->left->left = new node(4);
    root->left->right = new node(3);
    root->left->right->left = new node(4);
    root->right->left = new node(8);
    root->right->right = new node(6);
    root->right->right->left = new node(7);
    root->right->right->left->left = new node(9);
    boundaryTraversal(root);
    return 0;
}

