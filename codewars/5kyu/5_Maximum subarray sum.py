def max_sequence(arr):
    r = 0
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            r = max(r, sum(arr[i:j+1]))
    return r
