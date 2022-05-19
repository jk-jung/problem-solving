def create_message(s):
    r = [s]
    def f(x=None):
        if x is None:
            return ' '.join(r)
        r.append(x)
        return f
    return f