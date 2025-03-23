from itertools import groupby
def numbers_need_friends_too(n):
    t = [(k, len(list(v))) for k, v in groupby(str(n))]
    return int(''.join(k * (3 if v == 1 else v) for k, v in t))