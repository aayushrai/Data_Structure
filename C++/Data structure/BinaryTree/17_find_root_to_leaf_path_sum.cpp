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

vector<vector<int>> paths;
bool rootToLeafNodesPathSum(node* root,int sm){
    if(not root)
        return false;
    sm -= root->val;
    if(!root->left and !root->right){
        if(sm == 0)
            return true;
    }
    if(rootToLeafNodesPathSum(root->left,sm) or rootToLeafNodesPathSum(root->right,sm))
        return true;
    return false;
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
    cout << rootToLeafNodesPathSum(root,28);
   
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
// is any root to leaf sum is equal to given sum