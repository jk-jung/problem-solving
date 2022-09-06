from collections import Counter


class PrimeFactorizer:
    def __init__(self, x):
        self.factor = Counter()
        i = 2
        while i * i <= x:
            while x % i == 0:
                self.factor[i] += 1
                x //= i
            i += 1
        if x != 1:
            self.factor[x] = 1
