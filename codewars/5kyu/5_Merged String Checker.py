def is_merge(s, a, b):
    if len(s) == 0: return len(a) == 0 and len(b) == 0
    if len(a) > 0 and a[0] == s[0] and is_merge(s[1:], a[1:], b): return True
    if len(b) > 0 and b[0] == s[0] and is_merge(s[1:], a, b[1:]): return True
    return False

