import math
def champernowne_digit(n):
    if isinstance(n, type(True)) or not isinstance(n, int) or n <= 0: return math.nan
    if n == 1: return 0
    n -= 1
    for i in range(1, 100000000):
        cnt = (10 ** i - 10 ** (i - 1)) * i
        if cnt >= n:
            n -= 1
            x, y = divmod(n, i)
            t = 10 ** (i - 1) + x
            return int(str(t)[y])
        n -= cnt