def any_odd(x):
    x = x & ((1 <<32) - 1)
    return '1' in bin(x)[2:][::-1][1:][::2]
