
class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None


def constructB(start,end,posIndex,inorderDict,postorder):
    if start>end:
        return None,posIndex
    
    root = Node(postorder[posIndex])
    posIndex -= 1
    index = inorderDict[root.data]

    root.right,posIndex = constructB(index+1,end,posIndex,inorderDict,postorder)
    root.left,posIndex = constructB(start,index-1,posIndex,inorderDict,postorder)

    return root,posIndex
    
def PreOrderTraversal(root):
    if not root:
        return
    print(root.data)
    PreOrderTraversal(root.left)
    PreOrderTraversal(root.right)
    


if __name__ == "__main__":
    inorder = [4, 2, 1, 7, 5, 8, 3, 6]
    postorder = [4, 2, 7, 8, 5, 6, 3, 1]    
    inorderDict = {}
    for i,v in enumerate(inorder):
        inorderDict[v] = i

    posIndex = len(postorder)-1                        
    root,preIndex = constructB(0,len(inorder)-1,posIndex,inorderDict,postorder)
    PreOrderTraversal(root)
