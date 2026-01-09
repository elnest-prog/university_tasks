def any_satisfies(predicate, lst):
    for item in lst:
        if predicate(item):
            return True
    return False

def is_even(x):
    return x % 2 == 0

def is_positive(x):
    return x > 0

def is_long_string(s):
    return len(s) > 5

numbers = [1, 3, 5, 7, 8, 9]
strings = ["hi", "hello", "world", "!"]

print("1:", any_satisfies(is_even, numbers))
print("2:", any_satisfies(is_positive, [-1, -2, -3]))
print("3:", any_satisfies(is_long_string, strings))