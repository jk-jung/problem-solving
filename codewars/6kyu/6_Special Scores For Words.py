from collections import Counter
def find_word(num_let, max_ssw):
    r = (0, None)
    def f(x): return sum(ord(k) * v for k, v in Counter(x).items())
    for x in WORD_LIST:
        if len(x) == num_let and r[0] <= f(x) <= max_ssw:
            r = (f(x), x)
    return r[1]
