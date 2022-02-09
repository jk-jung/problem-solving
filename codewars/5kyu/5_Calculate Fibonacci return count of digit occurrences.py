from collections import Counter
def fib_digits(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a + b
    return sorted([(v, int(k)) for k, v in Counter(str(a)).items()], key=lambda x: (-x[0], -x[1]))