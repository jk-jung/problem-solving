def string_suffix(s):
    r = 0
    for i in range(len(s)):
        for j in range(i, len(s)):
            if s[j] == s[j - i]:
                r += 1
            else:
                break
    return r
