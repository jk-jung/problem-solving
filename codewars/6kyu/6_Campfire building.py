def is_constructable(a):
    for i in range(a):
        b = a - i * i
        if b < 0: return False
        if int(b ** .5) ** 2 == b: return True
