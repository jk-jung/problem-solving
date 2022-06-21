def create_iterator(f, n):
    def r(x):
        for i in range(n):
            x = f(x)
        return x
    return r
