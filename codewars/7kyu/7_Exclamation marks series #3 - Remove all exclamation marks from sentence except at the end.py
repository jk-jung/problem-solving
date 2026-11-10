def remove(s):
    a = len(s) - len(s.rstrip('!'))
    return s.replace('!', '') + '!' * a