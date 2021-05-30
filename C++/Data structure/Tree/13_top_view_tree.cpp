#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node* left;
    node* right;

    node(int val){
        this->val = val;
        left =  right = NULL;
    }
}node;

void _topView(node* root,map<int,int>& mp){
    if(not root)
        return ;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        if(mp.find(temp.second)==mp.end()){
            mp[temp.second] = temp.first->val;
        }
        if(temp.first->left)
            q.push(make_pair(temp.first->left,temp.second-1));
        if(temp.first->right)
            q.push(make_pair(temp.first->right,temp.second+1));
    }    
}
void topView(node* root){
    map<int,int> mp;
    _topView(root,mp);
    map<int,int> :: iterator it;
    for(it = mp.begin();it!=mp.end();it++){
        cout << it->second << " ";
    }
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->left->right->right = new node(9);
    topView(root);
    return 0;
}