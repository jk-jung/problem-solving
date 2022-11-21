from itertools import groupby
def convert(s):
    x = int(''.join(str(len(list(x[1]))) for x in groupby(s)))

    i = 2
    while i < x:
        while x % i == 0:
            x //= i
        if x == 1:
            x *= i
        i += 1
    return x