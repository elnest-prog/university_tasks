def create_pairs(arr, index=0, result=[]):
    if index >= len(arr):
        return result
    
    result.append([arr[index], arr[index] ** 2])
    return create_pairs(arr, index + 1, result)

n = 5
array = [1, 2, 3, 4, 5]
print("Полученный массив: ", create_pairs(array))
