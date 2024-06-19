def solve(s):
    a = s[::-1]
    r = 0
    for x, y in zip(a, s):
        if x != y: r += 1
    return r == 2 or r == 0 and len(s) % 2
