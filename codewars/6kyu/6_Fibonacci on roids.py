def custom_fib(a,b,n):
    m = len(a)
    while len(a) <= n:
        a.append(sum(a[-m + x] for x in b))
    return a[n]
