def array_conversion(a):
    for i in range(100):
        if len(a) == 1:
            return a[0]
        if i % 2:
            a = [x * y for x, y in zip(a[0::2], a[1::2])]
        else:
            a = [x + y for x, y in zip(a[0::2], a[1::2])]
