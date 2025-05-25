def is_balanced(para_str:str):
    mapping = {
        '}': '{',
        ']': '[',
        ')': '('
        }
    stack = []
    for ch in para_str:
        if(ch in mapping.values()):
            stack.append(ch)
        elif ch in mapping:
            if(not stack or mapping[ch] != stack.pop()):
                return False
    
    return not stack


test_string = "{[()]}"

print(is_balanced(test_string))