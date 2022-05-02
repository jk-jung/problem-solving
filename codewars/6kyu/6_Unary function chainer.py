def chained(fs):
    def _f(x):
        for f in fs:
            x = f(x)
        return x
    return _f