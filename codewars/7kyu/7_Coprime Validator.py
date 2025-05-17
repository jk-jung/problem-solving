def are_coprime(n,m):
    for i in range(2, n+1):
        if n%i == 0 and m%i == 0:
            return False
    return True
