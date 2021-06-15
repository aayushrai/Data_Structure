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

// Longest distance between any two nodes it's called diameter 
//  Example 1
// 1
//   \
//    2     ---->   diameter is 3 because longest distance between two nodes(1,3) is 3. 
//     \
//      3

// Example 2
//     1
//    / \
//   4   2     ---->   diameter is 5 because longest distance between two nodes(7,3) is 5. 
//  /     \
// 7       3

int _diameter(node* root,int &mxd){
    if(not root)
        return 0;
    int l = _diameter(root->left,mxd);
    int r = _diameter(root->right,mxd);
    int dia = l+r+1;
    if(dia > mxd)
        mxd = dia;
    return 1+max(l,r);  
}
int diameter(node* root){
    int mxd = 0;
    _diameter(root,mxd);
    return mxd;
}
int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(7);
    root->left->right = new node(3);
    // root->right->left = new node(2);
    // root->right->right = new node(5);
    // root->right->right->left = new node(5);
    cout << "Diameter: " << diameter(root) <<endl;
    return 0;
}