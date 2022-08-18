def valid_word(v, s):
    if len(s) == 0: return True
    for x in v:
        if s.startswith(x) and valid_word(v, s[len(x):]):
            return True
    return False
