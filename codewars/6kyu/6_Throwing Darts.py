def score_throws(a):
    r = sum(5 for x in a if x < 5)
    if len(a) > 0 and r == len(a) * 5:
        r += 100
    r += sum(5 for x in a if x <= 10)
    return r