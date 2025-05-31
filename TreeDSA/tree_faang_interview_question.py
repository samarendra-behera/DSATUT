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


def is_balanced(root):
    if root == None:
        return True, 0
    
    left, left_height = is_balanced(root.left)
    right, right_height = is_balanced(root.right)

    height = max(left_height, right_height) + 1

    return left and right and (abs(left_height-right_height) <= 1), height


def is_identical(root1, root2):

    if(root1== None and root2 == None):
        return True
    if(root1 == None and root2 != None):
        return False
    if(root1 != None and root2 == None ):
        return False
    else:
        left_check = is_identical(root1.left, root2.left)
        right_check = is_identical(root1.right, root2.right)
        if left_check and right_check and (root1.data == root2.data):
            return True
        else: 
            return False


def is_sum_tree(root):
    # base case
    if(root == None):
        return True, 0
    
    # leaf node
    if(root.left == None and root.right == None):
        return True, root.data
    
    left_check, left_sum = is_sum_tree(root.left)
    right_check, right_sum = is_sum_tree(root.right)

    if(left_check and right_check and (root.data == (left_sum + right_sum))):
        return True, 2 * root.data
    else:
        return False, 0 # here you also pass any value in second return


if __name__ == '__main__':
    root = build_from_level_order()
    level_order_traversal(root)

    # question 1 : get tree height
    # height = get_tree_height(root)
    # print(f"Tree height is {height}")

    # question 2 : get diameter of the tree
    # diameter, height = get_tree_diameter(root)
    # print(f"Three diameter is {diameter}")

    # question 3 : check for balance tree
    # print(f"It is a balance tree : ", is_balanced(root)[0])

    # question 4 : determine if two trees are identical
    # print("First tree data enter. ")
    # root1 = build_from_level_order()

    # print("Second tree data enter. ")
    # root2 = build_from_level_order()

    # print("First tree is :")
    # level_order_traversal(root1)

    # print("Second tree is :")
    # level_order_traversal(root2)

    # print(f"These two are identical tree {is_identical(root1, root2)}")

    # question 5 : check is sum tree
    print(f"It is a sum tree : {is_sum_tree(root)[0]}")
