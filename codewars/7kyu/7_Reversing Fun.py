def reverse_fun(n):
    n = list(n)
    for i in range(len(n)):
        n[i:] = n[i:][::-1]
    return ''.join(n)
