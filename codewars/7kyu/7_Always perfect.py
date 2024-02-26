def check_root(s):
    try:
        a = list(map(int, s.split(',')))
        assert len(a) == 4
        if not(a[0] + 1 == a[1] and a[1] + 1 == a[2] and a[2] + 1 == a[3]):
            return 'not consecutive'
        r = a[0] * a[1] * a[2] * a[3] + 1
        return f"{r}, {int(r ** .5)}"

    except: return 'incorrect input'
