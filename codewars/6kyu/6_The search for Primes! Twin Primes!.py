from gmpy2 import is_prime as p
def twin_prime(n):
    return len([(i - 1, i + 1) for i in range(3, n + 1) if p(i - 1) and p(i + 1)])
