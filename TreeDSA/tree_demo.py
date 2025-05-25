from collections import deque

class Node :
    def __init__(self, data:int):
        self.data = data
        self.left = None
        self.right = None


def build_tree(root):
    while True:
        try:
            data = int(input("Enter the data: "))
            break
        except ValueError:
            print("Please enter a number")
    root = Node(data)
    if(data == -1):
        return None
    
    print("Enter data for inserting in left of ", data)
    root.left = build_tree(root.left)
    print("Enter data for inserting in right of ", data)
    root.right = build_tree(root.right)

    return root


def level_order_traversal(root):
    d = deque()
    d.append(root)
    d.append(None)
    while(len(d) != 0):
        temp = d[0]
        d.popleft()

        if(temp) == None:
            print()
            if(len(d) != 0):
                d.append(None)
        else:
            print(temp.data, end=" ")
            if(temp.left):
                d.append(temp.left)
            if(temp.right):
                d.append(temp.right)


def inorder_traversal(root): # LNR

    if(not root ):
        return

    inorder_traversal(root.left)
    print(root.data, end=" ")
    inorder_traversal(root.right)


def preorder_traversal(root): # NLR
    if not root:
        return
    
    print(root.data, end=" ")
    preorder_traversal(root.left)
    preorder_traversal(root.right)


def postorder_traversal(root): # LRN
    if not root:
        return
    
    postorder_traversal(root.left)
    postorder_traversal(root.right)
    print(root.data , end=" ")

if __name__ == '__main__':
    root = None
    root = build_tree(root)
    # input 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_order_traversal(root)

    print("\n\n In order traversal \n")
    inorder_traversal(root)

    print("\n\n Pre order traversal \n")
    preorder_traversal(root)

    print("\n\n Post order traversal \n")
    postorder_traversal(root)