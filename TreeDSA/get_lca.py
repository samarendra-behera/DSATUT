from vertical_traversal import (level_order_traversal, build_from_level_order)

def get_lowest_common_ancestor(root, n1, n2):
    if(root == None):
        return None
    
    if(root.data == n1 or root.data == n2):
        return root
    
    left_return = get_lowest_common_ancestor(root.left, n1, n2)
    right_return = get_lowest_common_ancestor(root.right, n1, n2)

    if(left_return is not None and right_return is not None):
        return root
    elif(left_return is not None):
        return left_return
    elif(right_return is not None):
        return right_return
    else:
        return None
    

# Find out the Lowest common ancestor in a binary tree
if __name__ == '__main__':
    root = build_from_level_order()
    print("Tree Level Order Traversal: \n")
    level_order_traversal(root)

    lca = get_lowest_common_ancestor(root, 4, 5)
    print(" LCA of above tree for 4 and 5", lca.data)