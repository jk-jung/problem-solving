def create_multiplications(n):
    def f(i):
        return lambda x: i * x
    return [f(i) for i in range(n)]
