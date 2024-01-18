def generator(a):
    i = 1
    while True:
        yield f"{a} x {i} = {a*i}"
        i += 1
