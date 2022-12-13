def solved(s):
    n = len(s) // 2
    if len(s) % 2: s = s[:n] + s[n + 1:]
    return ''.join(sorted(s))
