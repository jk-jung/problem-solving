def sc(a,b,c):
    a = a + a + b + b - 4
    return a / (c + 1) if a % (c + 1) == 0 else 0