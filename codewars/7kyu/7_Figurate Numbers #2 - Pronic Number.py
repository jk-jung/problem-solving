def is_pronic(n):
    if n < 0: return False
    x = int(n**.5)
    return x*(x+1) == n
