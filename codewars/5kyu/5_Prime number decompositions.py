from collections import Counter
def getAllPrimeFactors(n):
    if type(n) != int or n <= 0: return []

    i = 2;
    r = []
    while i * i <= n:
        while n % i == 0:
            n //= i
            r.append(i)
        i += 1
    if n > 1: r.append(n)
    if len(r) == 0 and n == 1: r = [1]
    return r

def getUniquePrimeFactorsWithCount(n):
    r = Counter(getAllPrimeFactors(n))
    return [list(r.keys()), list(r.values())]


def getUniquePrimeFactorsWithProducts(n):
    r = getUniquePrimeFactorsWithCount(n)
    return [x ** y for x, y in zip(*r)]