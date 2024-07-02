def cool_string(s):
    if any(not x.isalpha() for x in s): return False
    for a, b in zip(s, s[1:]):
        if a.isupper() == b.isupper(): return False
    return True
