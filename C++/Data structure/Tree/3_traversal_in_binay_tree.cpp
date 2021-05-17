#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left, *right;

    TreeNode(int val){
        this->val = val;
        left =  right = NULL;
    }
};

struct TreeNode* insertLevelOrder(struct TreeNode* node,int key){
    struct TreeNode* nw = new TreeNode(key);
    if(!node)
        return nw;
    queue<struct TreeNode*>q;
    q.push(node);
    while(!q.empty()){
        struct TreeNode* crr = q.front();
        q.pop();
        if(crr->left ==NULL){
            crr->left = nw;
            return node;
        }
        else{
            q.push(crr->left);
        }
        if(crr->right ==NULL){
            crr->right = nw;
            return node;
        }
        else{
            q.push(crr->right);
        }
        
    }
    return node;

}
void postOrder(struct TreeNode* node){
    if(!node)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}



void preOrder(struct TreeNode* node){
    if(node == NULL)
        return;
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}



void inOrder(struct TreeNode* node){
    if(!node)
        return;
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

int main(){
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root = insertLevelOrder(root,7);

    postOrder(root);
    cout << "\n";
    inOrder(root);
    cout << "\n";
    preOrder(root);
    return 0;
}