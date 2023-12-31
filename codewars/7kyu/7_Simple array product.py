def solve(arr):
    a, b = 1, 1
    for x in arr:
        x.sort()
        t = [a * x[0], b * x[0], a * x[-1], b * x[-1]]
        a, b = min(t), max(t)
    return b
