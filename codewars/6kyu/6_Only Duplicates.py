def only_duplicates(s):
    return ''.join(x for x in s if s.count(x) > 1)
