#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    node *left,*right;

    node(int val) {
        this->val = val;
        left = right = NULL;
    }
}node;

int searchInInorder(vector<int>& inOrder,int key,int start,int end) {
    for(int i = start; i <= end; i++ ) {
        if (inOrder[i] == key) {
            return i;
        }
    }
    return end;
}

node* buildTree(vector<int>& preOrder, vector<int>& inOrder, int& preOrderPointer, int inOrderStart, int inOrderEnd) {
    if ( inOrderEnd < inOrderStart ) {
        return NULL;
    }
    node* nw = new node(preOrder[preOrderPointer]);
    int mid = searchInInorder(inOrder, preOrder[preOrderPointer], inOrderStart, inOrderEnd);
    preOrderPointer++;
    nw->left = buildTree(preOrder, inOrder, preOrderPointer, inOrderStart, mid - 1);
    nw->right = buildTree(preOrder, inOrder, preOrderPointer, mid + 1, inOrderEnd);
    return nw;
}

void inOrderTraversal(node* root) {
    if(!root)
        return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    vector<int> preOrder = { 1, 2, 4, 5, 3, 7};
    vector<int> inOrder = { 4, 2, 5, 1, 3, 7 };
    int inOrderPointer = 0;
    node* root = buildTree(preOrder, inOrder, inOrderPointer, 0 , preOrder.size()-1);
    inOrderTraversal(root);
}