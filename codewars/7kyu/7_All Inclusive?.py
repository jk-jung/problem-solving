def contain_all_rots(s, v):
    for i in range(len(s)):
        if s not in v:return False
        s = s[1:] + s[0]
    return True