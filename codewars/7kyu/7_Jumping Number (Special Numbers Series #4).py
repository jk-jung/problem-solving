def jumping_number(a):
    a = str(a)
    for x, y in zip(a, a[1:]):
        if abs(ord(x) - ord(y)) != 1:
            return "Not!!"
    return "Jumping!!"
