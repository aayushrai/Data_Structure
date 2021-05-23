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

void _diagonal_traversal(node *root,map<int,vector<int>>& mp,int dlevel){
    if(not root)
        return;
    mp[dlevel].push_back(root->val);
    _diagonal_traversal(root->left,mp,dlevel+1);
    _diagonal_traversal(root->right,mp,dlevel);
}
void diagonal_traversal(node* root){
    map<int,vector<int>> mp;
    _diagonal_traversal(root,mp,0);

    map<int,vector<int>> :: iterator it;
    for(it = mp.begin();it!=mp.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout << it->second[i] << " ";
        }
    }
    
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(8);
    root->left->right = new node(9);
    root->right->left = new node(10);
    diagonal_traversal(root);
    return 0;
}


//  \     \ 1
//   \   2 \  3
//   8\ 9,10\  
//       ^
//    preorder(given)
//  https://youtu.be/8ND-GB8hpJI