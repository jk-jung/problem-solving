import bisect
def is_happy(n):
    while n > 4:
        n = sum(int(d)**2 for d in str(n))
    return n == 1

v = list(filter(is_happy, range(1, 300000)))
def performant_numbers(n):
    return v[:bisect.bisect_right(v, n)]
