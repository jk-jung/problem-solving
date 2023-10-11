from preloaded import count_calls
from functools import wraps


def memoize(func):
    d = {}
    @wraps(func)
    def _f(x):
        if x in d: return d[x]
        d[x] = func(x)
        return d[x]
    return _f