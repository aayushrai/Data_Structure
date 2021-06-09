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
    if(!root1 or !root2)
        return false;
    if(root1->val == root2->val)
        return isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right);
    return false;

}
void isSubtree(node* root1,node* root2){
    if(!root1 or !root2)
        return ;
    if(root1->val == root2->val){
        cout<< isIdentical(root1,root2);
        return;
    }
    isSubtree(root1->left,root2);
    isSubtree(root1->right,root2);
}

int main(){

//  main tree
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

//  subtree 
    node* root2 = new node(5);
    root2->left = new node(8);
    root2->right = new node(6);
    root2->left->left = new node(10);
    root2->right->left = new node(7);
    root2->right->left->left = new node(9);

    isSubtree(root,root2);
    
    return 0;
}

//     1
//   /   \
//  2     5 
//   \   / \
//    3 8   6   
//   / /   /
//  4 10  7
//       /
//      9