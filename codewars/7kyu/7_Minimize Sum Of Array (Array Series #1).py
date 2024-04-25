def min_sum(arr):
    r = 0
    while arr:
        arr = sorted(arr)
        r += arr.pop(0) * arr.pop()
    return r
