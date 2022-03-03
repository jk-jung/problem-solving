def prod_int_part(n): # n the integer to be partitioned in products
    r, i = [], 2
    while i * i <= n:
        while n % i == 0:
            n //= i
            r.append(i)
        i += 1
    if n > 1: r.append(n)
    if len(r) <= 1: return [0, []]

    s = {tuple()}
    for x in r:
        nt = set()
        for lst in s:
            lst = list(lst)
            nt.add(tuple(sorted(lst + [x])))
            for i in range(len(lst)):
                lst[i] *= x
                nt.add(tuple(sorted(lst)))
                lst[i] //= x
        s = nt

    return [len(s) - 1, r]