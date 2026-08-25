def no_repeat(s):
    return next(x for x in s if s.count(x) == 1)
