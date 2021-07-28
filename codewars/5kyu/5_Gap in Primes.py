def is_p(x):
    m = int(x**.5)
    for i in range(2, m+1):
        if x % i == 0: return False
    return True

def gap(g, m, n):
    p = []
    for x in range(m, n+1):
        if is_p(x):
            if len(p) > 0 and x - p[-1] == g:
                return [p[-1], x]
            p.append(x)

    # your code