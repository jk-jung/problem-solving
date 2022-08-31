def f(s):
    n = len(s)
    for i in range(1, n + 1):
        if n % i == 0 and s[:i] * (n // i) == s:
            return (s[:i], n //i)