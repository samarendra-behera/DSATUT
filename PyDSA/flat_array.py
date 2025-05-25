def flat_array_list(row_list:list):
    result = []
    for item in row_list:
        if(isinstance(item, list)):
            result.extend(flat_array_list(item))
        else:
            result.append(item)
    
    return result


nested_list = [1, [2, 3], [4, [5, 6]], 7]
print(flat_array_list(nested_list))