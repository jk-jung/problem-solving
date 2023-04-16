import re
def censor_this(t, v):
    def f(x): return '*' * len(x[0])
    return ' '.join([re.sub('^(' + '|'.join(v) + ')$', f, x, flags=re.IGNORECASE) for x in t.split(' ')])