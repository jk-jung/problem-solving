def sum_of_threes(n):
    c = 0
    r = ''
    while n:
        if n % 3 == 2: return 'Impossible'
        if n % 3 == 1: r = f'3^{c}+' + r
        n //= 3
        c += 1
    return r.strip('+')
