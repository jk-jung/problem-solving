def squared_spiral(n):
    m = (int(n ** .5) + 1)// 2
    k = m * 2 + 1
    o = n - (k - 2) ** 2
    k -= 1
    if o < k: return (m, -m + 1 + o)
    elif o < 2 * k: return(m - o % k - 1, m)
    elif o < 3 * k: return (-m, m - 1 - o % k)
    else: return (-m + o % k + 1, -m)
