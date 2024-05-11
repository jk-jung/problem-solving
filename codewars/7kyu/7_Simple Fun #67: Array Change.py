def array_change(arr):
    r, y = 0, arr[0] - 1
    for x in arr:
        y = max(y + 1, x)
        if x < y:
            r += y - x
    return r
