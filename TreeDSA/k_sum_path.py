from vertical_traversal import (build_from_level_order, level_order_traversal)


'''
    Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values 
    in the path equals k. A path can start and end at any node within the tree but must always
    move downward (from parent to child).
'''

class Solution:
    k = None
    root = None
    count = 0
    path = []

    def __init__(self, root, k):
        self.root = root
        self.k = k

    def solve(self, root, k):
        if root is None:
            return None
        
        self.path.append(root.data)

        self.solve(root.left, k)
        self.solve(root.right, k)

        sum = 0
        for i in range(len(self.path) - 1 , -1, -1):
            sum+=self.path[i]
            if(sum == self.k):
                self.count += 1

        self.path.pop()


    def get_k_sum_path(self):
        self.solve(self.root, self.k)
        
        return self.count

if __name__ == '__main__':
    root = build_from_level_order()
    print("Tree Level Order Traversal: \n")
    level_order_traversal(root)

    k = 6
    solution = Solution(root, k)
    count = solution.get_k_sum_path()
    print(f"K({k}) sum path is : {count}")


