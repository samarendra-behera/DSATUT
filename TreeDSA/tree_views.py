from collections import deque
from tree_traversal import build_from_level_order, level_order_traversal


def tree_top_view(root):
    track_map = {}
    q = deque()

    result = []
    if(root is None):
        return result
    
    q.append((root, 0))

    while q:
        curr_node, hd = q.popleft()

        if(hd not in track_map.keys()):
            track_map[hd] = curr_node.data

        if(curr_node.left):
            q.append((curr_node.left, hd - 1))
        if(curr_node.right):
            q.append((curr_node.right, hd + 1))
    result = [value for key, value in sorted(track_map.items())]
    return result

def tree_bottom_view(root):
    track_map = {}
    q = deque()

    result = []
    if(root is None):
        return result
    
    q.append((root, 0))

    while q:
        curr_node, hd = q.popleft()

        track_map[hd] = curr_node.data

        if(curr_node.left):
            q.append((curr_node.left, hd - 1))
        if(curr_node.right):
            q.append((curr_node.right, hd + 1))
    result = [value for key, value in sorted(track_map.items())]
    return result

def tree_left_view(root, ans:list, level:int):
    if(root is None):
        return ans
    
    if(len(ans) == level):
        ans.append(root.data)
    
    tree_left_view(root.left, ans, level + 1)
    tree_left_view(root.right, ans, level + 1)

def tree_right_view(root, ans:list, level:int):
    if(root is None):
        return ans
    
    if(len(ans) == level):
        ans.append(root.data)
    
    tree_right_view(root.right, ans, level + 1)
    tree_right_view(root.left, ans, level + 1)


if __name__ == '__main__':
    root = build_from_level_order()

    print("\n\n Level order traversal \n")
    level_order_traversal(root)

    print("\n\n Tree Top View \n")
    top_view = tree_top_view(root)
    print(top_view)
    
    print("\n\n Tree Bottom View \n")
    bottom_view = tree_bottom_view(root)
    print(bottom_view)
    
    print("\n\n Tree Left View \n")
    left_view = []
    tree_left_view(root, left_view, 0)
    print(left_view)
    
    print("\n\n Tree Right View \n")
    right_view = []
    tree_right_view(root, right_view, 0)
    print(right_view)