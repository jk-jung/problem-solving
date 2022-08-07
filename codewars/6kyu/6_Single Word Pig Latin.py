def pig_latin(s):
    s = s.lower()
    if not s.isalpha(): return None
    if not any(x in s for x in 'aeiou'): return s + 'ay'
    if s[0] in 'aeuio': return s + 'way'
    while s[0] not in 'aeiou': s = s[1:] + s[0]
    return s + 'ay'