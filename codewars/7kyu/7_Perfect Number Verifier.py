def is_perfect(n):
    if n == 1: return False
    r = 1
    for i in range(2, int(n ** .5 + 1)):
        if n % i == 0:
            r += i
            if i != n // i:
                r += n // i
    return n == r