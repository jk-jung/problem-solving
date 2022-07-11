def is_sum_of_cubes(s):
    r, c = [], ''
    s += 'z'
    for x in s:
        if x.isdigit():
            c += x
        if (not x.isdigit() and c) or len(c) == 3:
            if int(c) == sum(int(y) ** 3 for y in c):
                r.append(c)
            c = ''
    if r:
        return ' '.join(r) + f" {sum(int(x) for x in r)} Lucky"
    return "Unlucky"
