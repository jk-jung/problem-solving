from itertools import permutations

def largest_arrangement(v):
    def f(x):
        r = x
        for i in range(1, 11):
            if i != len(x):
                r *= i
        return r

    return int(''.join(sorted(map(str, v), key=f, reverse=True)))