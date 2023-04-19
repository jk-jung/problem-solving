def solve(a, b):
    for x in a:
        if x not in b:
            if a.count(x) >= 2: return 1
    return 2
