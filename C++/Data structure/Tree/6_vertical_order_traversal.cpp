#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node* left;
    node*  right;

    node(int val){
        this->val = val;
        left = right =NULL;
    }
}node;

void _vertical_traversal(node* root,map<int,vector<int>>& mp){
    if(not root)
        return;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp = q.front();
        q.pop();
        mp[temp.second].push_back(temp.first-> val);
        if(temp.first->left)
            q.push(make_pair(temp.first->left,temp.second-1));
        if(temp.first->right)
            q.push(make_pair(temp.first->right,temp.second+1));
    }   
}

void vertical_traversal(node* root){
    if(not root)
        return;
    map<int,vector<int>> mp;
    _vertical_traversal(root,mp);

    map<int,vector<int>> :: iterator it;
    for(it = mp.begin();it!= mp.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout << it->second[i] << " ";
        }
    }

    
}
int main(){
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(6);
    root->left->left = new node(8);
    root->left->right = new node(9);
    root->right->left = new node(10);
    vertical_traversal(root);
    return 0;
}


    // Vertical traversal
    //   |   |  5  |
    //   | 4 |     | 6
    // 8 |   | 9 10|
    //          ^
    //        inorder(given)

    //  https://youtu.be/8ND-GB8hpJI
      