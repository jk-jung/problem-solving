import functools
def htmlize(tag):
    def f(_f):
        @functools.wraps(_f)
        def t(*args, **kwargs):
            return f"<{tag}>{_f(*args, **kwargs)}</{tag}>"
        return t
    return f
