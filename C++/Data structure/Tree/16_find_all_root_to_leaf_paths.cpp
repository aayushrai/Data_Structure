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
void rootToLeafNodesPaths(node* root,vector<int> path){
    if(not root)
        return;
    path.push_back(root->val);
    if(!root->left and !root->right){
        paths.push_back(path);
        return;
    }
    rootToLeafNodesPaths(root->left,path);
    rootToLeafNodesPaths(root->right,path);
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
    rootToLeafNodesPaths(root,{});
    for(int i=0;i<paths.size();i++){
        for(int j=0;j<paths[i].size();j++){
            cout << paths[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
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