//         *
//       /   \
//     +      -
//    / \    / \
//   3  4   6   4 
// infix  ->  "3+4*6-4"     <- (inorder traversal of tree) computer not able to solve infix that why we use prefix and postfix
// prefix ->  "*+34-64"     <- (preorder traversal of tree) this one is easily understable
// postfix->  "34+64-*"     <- (postorder traversal of tree)

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    char val;
    node* left;
    node* right;

    node(char val){
        this->val = val;
        left = right = NULL;
    }
}node;

node* prefixToExpressionTree(string st,int& i){
    if(i>=st.length())
        return NULL;
    node* nw = new node(st[i]);
    string operators = "*-+/";
      i += 1;
    if(operators.find(st[i-1])<operators.length()){
        nw->left = prefixToExpressionTree(st,i);
        nw->right = prefixToExpressionTree(st,i);
    }
    return nw;

}
void inorderTraversal(node* root){
    if(!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main(){
    string prefix = "*+34-64";
    int i = 0;
    node* root = prefixToExpressionTree(prefix,i);
    inorderTraversal(root);
}