def triple_trouble(a, b, c):
    return ''.join(''.join(x) for x in zip(a,b,c))
