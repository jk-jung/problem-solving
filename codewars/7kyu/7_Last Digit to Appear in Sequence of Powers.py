def LDTA(n):
    try:
        m = n
        c = {}
        if n == 1: return None

        while len(c) <= 10:
            for x in str(n):
                if x not in c and len(c) == 9:
                    return int(x)
                c[x] = 1
            n *= m
    except:
        return None
