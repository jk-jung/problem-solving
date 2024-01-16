def reverse_number(n):
    n = str(n)[::-1]
    if n[-1] == '-':
        n = n[-1] + n[:-1]
    return int(n)
