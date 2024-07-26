def arr2bin(arr):
    r = 0
    for x in arr:
        if type(x) != type(1): return False
        r += x
    return bin(r)[2:]
