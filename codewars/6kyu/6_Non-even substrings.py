def solve(s):
    return sum((i + 1 for i in range(len(s)) if int(s[i]) % 2))