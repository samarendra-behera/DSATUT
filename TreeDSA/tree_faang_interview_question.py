from collections import deque

from tree_traversal import (
    build_from_level_order,
    level_order_traversal
)


def get_tree_height(root):

    if root == None:
        return 0
    
    left_height = get_tree_height(root.left)
    right_height = get_tree_height(root.right)

    return max(left_height, right_height) + 1


def get_tree_diameter(root):
    if(root == None):
        return 0, 0
    
    left_diameter, left_height = get_tree_diameter(root.left)
    right_diameter, right_height = get_tree_diameter(root.right)

    op3 = left_height + right_height + 1
    
    height = max(left_height, right_height) + 1
    diameter = max(left_diameter, right_diameter, op3)
    return diameter, height



if __name__ == '__main__':
    root = build_from_level_order()
    level_order_traversal(root)

    # question 1 : get tree height
    height = get_tree_height(root)
    print(f"Tree height is {height}")

    # question 2 : get diameter of the tree
    diameter, height = get_tree_diameter(root)
    print(f"Three diameter is {diameter}")