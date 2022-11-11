import copy
def expansion(m, k):
    if k == 0: return m
    m = copy.deepcopy(m)
    n = len(m)
    t = list(zip(*m))
    m.append([])
    last = 0
    for i in range(n):
        m[i].append(sum(m[i]))
        m[-1].append(sum(t[i]))
        last += m[i][i]
    m[-1].append(last)
    return expansion(m, k - 1)