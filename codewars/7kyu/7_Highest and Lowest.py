def high_and_low(n):
    x = [int(x) for x in n.split(' ')]
    return f'{max(x)} {min(x)}'