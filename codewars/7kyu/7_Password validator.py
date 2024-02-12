def password(s):
    a = 'abcdefghijklmnopqrxtuvwxyz'
    if len(s) < 8: return False
    if not (set(a) & set(s)): return False
    if not (set(a.upper()) & set(s)): return False
    if not (set('1234567890') & set(s)): return False
    return True
