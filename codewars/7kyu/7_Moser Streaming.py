from math import comb
def moser():
    i = 1
    while True:
        yield comb(i, 2) + comb(i, 4) + 1
        i += 1
