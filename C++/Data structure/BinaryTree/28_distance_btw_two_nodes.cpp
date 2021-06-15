#include<iostream>

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

node* LCA(node* root,int d1,int d2){
    if(!root)
        return NULL;
    if(root->val == d1 or root->val == d2)
        return root;
    node* leftLCA = LCA(root->left,d1,d2);
    node* rightLCA = LCA(root->right,d1,d2);

    if(leftLCA and rightLCA)
        return root;
    if(leftLCA) return leftLCA;
    if(rightLCA) return rightLCA;
    
    return NULL;
    
}

int distance(node* lca,int node,int dis){
    if(!lca)
        return -1;
    if(lca->val == node){
        return dis;
    }
    return max(distance(lca->left,node,dis+1),distance(lca->right,node,dis+1));
}

int  distanceBtwTwoNodes(node* root,int a,int b){
    node* lca = LCA(root,a,b);
    return distance(lca,a,0) + distance(lca,b,0);
}

int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->left->left = new node(3);
    root->right = new node(2);
    root->right->left = new node(4);
    root->right->right = new node(5);

    cout << distanceBtwTwoNodes(root,3,5) << endl;
    // For explanation check draw folder

}