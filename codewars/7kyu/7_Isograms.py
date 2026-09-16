def is_isogram(s):
    return len(s) == len(set(list(s.lower())))
