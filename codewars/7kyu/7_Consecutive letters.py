def solve(s):
    s = sorted(s)
    return all(ord(x) + 1 == ord(y) for x, y in zip(s, s[1:]))