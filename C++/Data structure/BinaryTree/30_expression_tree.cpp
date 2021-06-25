//         *
//       /   \
//     +      -
//    / \    / \
//   3  4   6   4 
// infix  ->  "3+4*6-4"     <- (inorder traversal of tree) computer not able to solve infix that why we use prefix and postfix
// prefix ->  "*+34-64"     <- (preorder traversal of tree) this one is easily understable
// postfix->  "34+64-*"     <- (postorder traversal of tree)

// node* gET(int *i,string prefix){
//     if(prefix[i] is operand)
//         return new node(operand)
//     else{
//         node* temp = new node(operator);
//         i += 1;
//         temp.left = gET(i,prefix)
//         i += 1;
//         temp.right = gET(i,prefix)
//         return temp;
//     }
// }