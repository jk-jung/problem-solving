import numpy as np
def count_digit(n, digit, base=10, from_base=10):
    r, b = 0, 1
    for x in n[::-1].lower():
        if not x.isdigit(): x = 10 + ord(x) - ord('a')
        r += b * int(x)
        b *= from_base

    r = np.base_repr(r, base=base).lower()
    return len([x for x in r if x == digit])
