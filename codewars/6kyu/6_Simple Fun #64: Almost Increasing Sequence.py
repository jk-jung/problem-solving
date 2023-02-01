def almost_increasing_sequence(s, ck=True):
    for i in range(1, len(s)):
        if s[i - 1] >= s[i]:
            if ck:
                return almost_increasing_sequence(s[:i-1] + s[i:], False) or almost_increasing_sequence(s[:i] + s[i + 1:], False)
            else:
                return False
    return True
