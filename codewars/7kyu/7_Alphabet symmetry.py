def solve(strings : list[str]) -> list[int]:
    r = []
    for x in strings:
        r.append(sum(x == y for x, y in zip('abcdefghijklmnopqrstuvwxyz', x.lower())))
    return r
