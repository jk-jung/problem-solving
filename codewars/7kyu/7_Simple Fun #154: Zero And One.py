def zero_and_one(s):
    r, i = len(s), 1
    while i < len(s):
        if s[i] != s[i - 1]:
            r -= 2
            i += 2
        else: i += 1
    return r
