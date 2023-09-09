from collections import Counter
def solve(v,n):
    r = 0
    for i, x in enumerate(v):
        if x == 'D':
            for j in range(i - n, i + n + 1):
                if 0 <= j and j < len(v) and v[j] == 'C':
                    r += 1
                    v[j] = 'X"'
                    break
    return r