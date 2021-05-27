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

// print the node which are visible when you saw tree from left 
//  Example 1
//                 1
//                 \
// person  --->     2     if person saw tree from left the nodes visible is (1,2,7)
//                 / \
//                7   3

// Example 2
//     1
//    / \
//   4   2     ---->   if person saw tree from left the nodes visible is (1,4,7)
//  /     \
// 7       3

void leftView(node* root){
     
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
    return 0;
}