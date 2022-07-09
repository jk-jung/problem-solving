def solve(s):
    s = list(s)
    def ck(v): return v == list(reversed(v))
    if ck(s): return 'OK'
    for i in range(len(s)):
        if ck(s[:i] + s[i + 1:]):
            return 'remove one'
    return 'not possible'