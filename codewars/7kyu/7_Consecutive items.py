def consecutive(arr, a, b):
    for x, y in zip(arr, arr[1:]):
        if x == a and y == b:
            return True
        if x == b and y == a:
            return True
    return False