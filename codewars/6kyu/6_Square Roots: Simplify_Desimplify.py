def simplify(n):
    r = 1
    for i in range(n, 0, -1):
        k = i * i
        if n % k == 0:
            r = i
            n //= k
            break
    if n == 1: return str(r)
    if r > 1: return f'{r} sqrt {n}'
    return f'sqrt {n}'


def desimplify(s):
    x = list(map(int, ('0'+s).split('sqrt')))
    if len(x) == 1: x.append(1)
    return max(1, x[0]) ** 2 * x[1]
