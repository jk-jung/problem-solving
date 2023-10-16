def loneliest(s):
    s = str(s)
    def f(k):
        x = int(s[k])
        r = -x
        for i in range(k - x, k + x + 1):
            if 0 <= i < len(s):
                r += int(s[i])
        return r
    m = min(f(i) for i in range(len(s)))
    for i in range(len(s)):
        if s[i] == '1' and f(i) == m: return True
    return False
