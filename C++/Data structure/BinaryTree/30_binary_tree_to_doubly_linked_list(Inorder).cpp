#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
}TreeNode;

typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val){
        this->val = val;
        next = prev = NULL;
    }
}ListNode;

void inorder(TreeNode* root,ListNode* head){
    if(not root)
        return;
    inorder(root->left,head);
    head->next = new ListNode(root->val);
    head->next->prev = head;
    inorder(root->right,head->next);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(4);
    ListNode* head = NULL;
    inorder(root,head);
}