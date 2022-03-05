def aks_test(p):
    if p == 1: return False
    s = p
    for i in range(2, (p + 1) // 2 + 1):
        s = s * (p - i + 1) // i
        if s % p: return False
    return True
s