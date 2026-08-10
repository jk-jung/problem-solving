def tricky_doubles(n):
    return n if str(n)[: len(str(n)) // 2] * 2 == str(n) else n * 2
