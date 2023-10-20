import re
import random

def mix_words(st):
    def f(x):
        y = list(x[2])
        while y == list(x[2]) and len(y) != 1:
            random.shuffle(y)
        return x[1] + ''.join(y) + x[3]
    r= re.sub('([a-zA-Z])([a-zA-Z]+)([a-zA-Z])', f, st)
    return r
