def plastic_balance(l):
    while l:
        if sum(l) == (l[0] + l[-1]) * 2:
            return l
        l = l[1:-1]
    return []
