from math import log

r = [0 for _ in range(1000001)]
r[0] = 1
for i in range(1, 1000001):
    r[i] = log(i, 10) + r[i - 1]


def factor_digit(n):
    return int(r[n])


# def factor_digit(n):
#     if n < 0:
#         return 0
#     if n <= 1:
#         return 1
#
#     # Kamenetsky formula
#     x = ((n * math.log10(n / math.e) + math.log10(2 * math.pi * n) / 2.0))
#     return math.floor(x) + 1
