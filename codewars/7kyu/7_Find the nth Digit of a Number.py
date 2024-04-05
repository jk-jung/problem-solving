def find_digit(a, b):
    a = str(abs(a))[::-1]
    b -= 1
    if b >= len(a): return 0
    return int(a[b]) if 0 <= b < len(a)  else -1
