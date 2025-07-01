from collections import defaultdict, deque
from tree_traversal import build_from_level_order, level_order_traversal


def vertical_traversal(root):
    track_map = defaultdict(list)
    d = deque()
    mn, mx = 0, 0
    if(root == None):
        return root
    
    d.append((root, 0))

    while d:
        temp = d.popleft()
        
        front_node = temp[0]
        hd = temp[1]
        track_map[hd].append(front_node.data)

        if(front_node.left):
            d.append((front_node.left, hd - 1))
        if(front_node.right):
            d.append((front_node.right, hd + 1))
        
        mn = min(mn, hd)
        mx = max(mx, hd)
    
    res = []
    for i in range(mn, mx +1):
        res.append(track_map[i])

    return res
    


if __name__ == '__main__':
    root = build_from_level_order()

    print("\n\n Level order traversal \n")
    level_order_traversal(root)

    print("\n\n Vertical traversal \n")
    vertical_traversal_result = vertical_traversal(root)
    print(vertical_traversal_result)