def cartesian_product(list1, list2):
    def helper(lst1, lst2, acc):
        if not lst1:
            return acc
        else:
            return helper(lst1[1:], lst2,  add_pairs(lst1[0], lst2, acc))
    
    def add_pairs(x, ys, acc):
        if not ys:
            return acc
        else:
            return add_pairs(x, ys[1:], acc +[(x, ys[0])] )
    
    return helper(list1, list2, [])
print(cartesian_product([1, 2, 3], ['a', 'b', 'c']))
