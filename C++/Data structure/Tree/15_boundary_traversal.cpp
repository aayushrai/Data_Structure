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

//     1
//   /   \
//  2     5
//   \   / \
//    3 8   6
//   /     /
//  4     7
//       /
//      9

// boundary traversal  1 2 3 4 8 9 7 6 5
// root -> 1
// left boundary(without leaf node 4 )(top down) -> 2 3 
// leaf nodes(left to right) -> 4 8 9
// right boundary(without leaf node 9 )(bottom up) -> 7 6 5

// for boundary traversal 
// first step, in first step we check root exist or not, if root exist then print it;
// second step, in second step we are printing left boundary without leaf node top to down(level order)
// third step, in third step we are printing leaf nodes left to right
// fourth step, in fourth step we are printing right boundary without leaf node bottom up(level order)
// note left and right boundary without leaf node because if we include leaf node it going to print twise because they are also going to add in leaf node third step.

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

