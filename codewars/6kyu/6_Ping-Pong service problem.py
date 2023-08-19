def service(s):
    a = sum(map(int, s.split(':')))
    t = 5
    if a >= 40:
        a -= 40
        t = 2

    a, b = divmod(a, t)

    return 'second' if a % 2 else 'first'
