def solve(s):
    r = 0
    for i in range(1, len(s) // 2 + 1):
        if s[:i] == s[-i:]:
            r = i
    return r
