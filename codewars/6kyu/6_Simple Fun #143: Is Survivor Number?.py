def survivor(n):
    for i in range(2, n + 1):
        if n < i: break
        if n % i == 0: return False
        n -= n // i
    return True
