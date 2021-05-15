#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};


struct TreeNode* insertNode(struct TreeNode* root,int key){
    struct TreeNode* nw = new TreeNode(key);
    if(not root)
        return nw;
    queue<struct TreeNode*>q;
    q.push(root);
    while(q.size()){
        struct TreeNode* rt = q.front();
        q.pop();
        if(rt->left == NULL){
            rt->left = nw;
            return root;}
        else
            q.push(rt->left);
        
        if(rt->right==NULL){
            rt->right = nw;
            return root;}
        else
           q.push(rt->right);
    }
    return root;
    
}

void preoder(struct TreeNode* node){
    if(not node)
        return;
    cout << node->val << " ";
    preoder(node->left);
    preoder(node->right);
}


int main(){
    struct TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root = insertNode(root,88);
     root = insertNode(root,77);
          root = insertNode(root,7);
    preoder(root);
    return 0;
}


