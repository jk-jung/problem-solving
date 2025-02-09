def filter_long_words(s, n):
    return [x for x in s.split() if len(x) > n]
