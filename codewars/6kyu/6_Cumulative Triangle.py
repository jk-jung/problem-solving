def cumulative_triangle(n):
    s = n * (n + 1) // 2
    def f(x):
        return x * (x + 1) // 2
    return f(s) - f(s - n)
