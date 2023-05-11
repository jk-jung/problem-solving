def length_of_railway(s):
    s = [x.count('哐当') for x in s.split('呜呜呜')]
    r = 0
    for i, x in enumerate(s):
        r += x * 10 + (x * 10) * (i % 2)
    return r
