from itertools import combinations
def pythagorean_triplet(n):
    v = set()
    for i in range(1, int(n ** .5) + 1):
        if n % i == 0:
            v.add(i)
            v.add(n // i)
    for x, y in combinations(v, 2):
        if n % (x * y) != 0: continue
        z = n // (x * y)
        if x ** 2 + y ** 2 == z ** 2:
            return [x, y, z]
