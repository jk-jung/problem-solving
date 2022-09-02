def solution(n):
    n -= 1
    def f(x):
        return (n // x) * (n // x + 1) // 2 * x
    return f(3) + f(5) - f(15)
