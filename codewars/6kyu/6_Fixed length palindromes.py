def palin(a,b):
    if a == 2: return int(str(b) * 2)
    n = (a + 1) // 2
    m = str(int('1' + '0' * (n - 1)) + b - 1)
    return int(m + m[::-1][a % 2:])
