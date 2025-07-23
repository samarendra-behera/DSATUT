from tree_traversal import level_order_traversal

class Node :
    def __init__(self, data:int):
        self.data = data
        self.left = None
        self.right = None

# Binary Tree from Inorder and Postorder
'''
    Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays inorder[] 
    and postorder[] respectively. The task is to construct a unique binary tree from 
    these traversals and return its root.
    Driver code will print the preorder traversal of the constructed tree.

    Note: The inorder and postorder traversals contain unique values, and 
        every value present in the postorder traversal is also found in the 
        inorder traversal.
'''
class Solution:
    def buildTree(self, in_order, post_order):
        self.index_map = {v:i for i, v in enumerate(in_order)}
        self.post_index = len(post_order) -1
        
        def helper(in_order_start, in_order_end):
            if(self.post_index <0 or in_order_start > in_order_end):
                return None
            
            val = post_order[self.post_index]
            root = Node(val)
            
            position = self.index_map[val]
            
            self.post_index -= 1
            
            root.right = helper(position + 1, in_order_end)
            root.left = helper(in_order_start, position -1)
            
            return root
        
        return helper(0, len(in_order) - 1)

# Binary Tree from Inorder and Preorder
'''
    Given inorder and preorder traversals of a binary tree(having n nodes) in the arrays inorder[] 
    and preorder[] respectively. The task is to construct a unique binary tree from 
    these traversals and return its root.
    Driver code will print the preorder traversal of the constructed tree.

    Note: The inorder and preorder traversals contain unique values, and 
        every value present in the preorder traversal is also found in the 
        inorder traversal.
'''
class SolutionTwo:
    def buildTree(self, in_order, pre_order):
        self.index_map = {v:i for i, v in enumerate(in_order)}
        self.pre_index = 0
        
        def helper(in_order_start, in_order_end):
            if(self.pre_index >= len(pre_order) or in_order_start > in_order_end):
                return None
            
            val = pre_order[self.pre_index]
            root = Node(val)
            
            position = self.index_map[val]
            
            self.pre_index += 1
            
            root.left = helper(in_order_start, position -1)
            root.right = helper(position + 1, in_order_end)
            
            return root
        
        return helper(0, len(in_order) - 1)

if __name__ == '__main__':
    # Binary Tree from Inorder and Postorder
    in_order = [4, 2, 5, 1, 6, 3, 7]
    post_order = [4, 5, 2, 6, 7, 3, 1]
    solution = Solution()
    root = solution.buildTree(in_order, post_order)
    level_order_traversal(root) # [1, 2, 3, 4, 5, 6, 7]

    # Binary Tree from Inorder and Preorder
    in_order = [4, 2, 5, 1, 6, 3, 7]
    pre_order = [1, 2, 4, 5, 3, 6, 7]
    solution = SolutionTwo()
    root = solution.buildTree(in_order, pre_order)
    level_order_traversal(root) # [1, 2, 3, 4, 5, 6, 7]