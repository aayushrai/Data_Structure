class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None


def constructB(start,end,preIndex,inorderDict,preorder):
    if start>end:
        return None,preIndex
    
    root = Node(preorder[preIndex])
    preIndex += 1
    index = inorderDict[root.data]

    root.left,preIndex = constructB(start,index-1,preIndex,inorderDict,preorder)
    root.right,preIndex = constructB(index+1,end,preIndex,inorderDict,preorder)

    return root,preIndex
    
def PreOrderTraversal(root):
    if not root:
        return
    print(root.data)
    PreOrderTraversal(root.left)
    PreOrderTraversal(root.right)
    


if __name__ == "__main__":
    inorder = [4, 2, 1, 7, 5, 8, 3, 6]
    preorder = [1, 2, 4, 3, 5, 7, 8, 6]
    inorderDict = {}
    for i,v in enumerate(inorder):
        inorderDict[v] = i

    preIndex = 0                        
    root,preIndex = constructB(0,len(inorder)-1,preIndex,inorderDict,preorder)
    print(root)
    PreOrderTraversal(root)
