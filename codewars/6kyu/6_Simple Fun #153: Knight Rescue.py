def knight_rescue(N,x,y):
    for n in N:
        z = abs(x * n + y)

        a = 2
        b = 1 + n * n
        if b % 2 != a % 2: return True
        elif z % 2 == 0: return True
    return False
