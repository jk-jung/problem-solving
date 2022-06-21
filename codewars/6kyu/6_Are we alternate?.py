def is_alt(s):
    t = 'aeiou'
    if s[0] in t:
        s = 'b' + s
    for i in range(len(s)):
        if i % 2:
            if s[i] not in t:
                return False
        else:
            if s[i] in t:
                return False
    return True