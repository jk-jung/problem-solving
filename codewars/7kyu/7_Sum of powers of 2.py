# return an array of numbers (that are a power of 2)
# for which the input "n" is the sum
def powers(n):
    r = []
    t = 1
    while n:
        if n & 1:r.append(t)
        n >>= 1
        t <<= 1
    return r