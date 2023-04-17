def simplify(n):
    n = str(n)
    return '+'.join(f'{x}{"*1" + "0" * (len(n) - i - 1) if len(n) - 1!= i else ""}' for i, x in enumerate(n) if x != '0')
