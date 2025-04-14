def baum_sweet():
    n = 0
    while True:
        t = bin(n).split('b')[-1].split('1')
        yield 1 if all(len(x) % 2 == 0 for x in t) or n == 0 else 0
        n += 1
