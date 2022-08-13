def split_odd_and_even(n):
    r = []
    for x in str(n):
        if not r or int(r[-1]) % 2 != int(x) % 2:
            r.append(x)
        else:
            r[-1] += x
    return list(map(int, r))
