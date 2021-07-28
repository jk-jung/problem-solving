def isPP(n):
    m = int(n**.5)
    for i in range(2, m+2):
        if n % i  == 0:
            nn = n
            cnt = 0
            while n % i == 0:
                n //= i
                cnt += 1
            if n == 1: return [i, cnt]
            n = nn
    return