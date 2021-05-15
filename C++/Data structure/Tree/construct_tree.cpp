#include<iostream>
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



void preoder(struct TreeNode* node){
    if(not node)
        return;
    cout << node->val << " ";
    display(node->left);
    display(node->right);
}


int main(){
    struct TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    preoder(root);
    return 0;
}
