def unusual_sort(a):
    def f(x):
        if isinstance(x, str):
            if x.isdigit():
                return (1, x, 1)
            return (0, x, 0)
        return (1, str(x), 0)
    return sorted(a, key=f)
