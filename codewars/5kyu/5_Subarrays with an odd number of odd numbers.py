def solve(arr):
    d = [1, 0]
    r, st = 0, 0
    for x in arr:
        if x % 2: st ^= 1
        d[st] += 1
        r += d[st ^ 1]
    return r