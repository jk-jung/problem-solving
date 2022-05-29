def loose_change(x):
    r = {'Quarters': 0, 'Dimes': 0, 'Nickels': 0, 'Pennies': 0}
    x = int(x)
    if x <= 0:
        return r
    for k, v in zip(r, [25, 10, 5, 1]):
        r[k] = x // v
        x %= v
    return r
