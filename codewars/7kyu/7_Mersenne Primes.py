from gmpy2 import is_prime

def valid_mersenne(n):
    return is_prime(2 ** n - 1)
