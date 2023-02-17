def p_num(n):
    r = 1
    for i in range(1, 100000):
        if r == n: return True
        if r > n: break
        r += i * 3 + 1
    return False

def g_p_num(n):
    if p_num(n): return True
    r = 1
    for i in range(1, 100000):
        r += i * 3 + 1
        if r - i * 5 == n : return True
        if r - i * 5 > n: break
    return False


def s_p_num(n):
    return int(n ** .5) ** 2 == n and  p_num(n)
