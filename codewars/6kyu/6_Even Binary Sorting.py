def even_binary(n):
    n = n.split(' ')
    t = sorted(x for x in n if x[-1] == '0')
    for i in range(len(n)):
        if n[i][-1] == '0': n[i] = t.pop(0)
    return ' '.join(n)
