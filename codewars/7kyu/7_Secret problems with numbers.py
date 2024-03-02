def secret_number(n):
    a = bin(n).count('0') ** 2
    b = bin(n).count('1') ** 2
    return b if n % 2 else a
