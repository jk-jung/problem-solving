def divisible_by_three(s):
    t = sum(map(int, s))
    while t > 0:
        t -= 3
    return t == 0
