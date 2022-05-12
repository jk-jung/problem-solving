def what_century(x):
    x = (int(x) - 1) // 100 + 1
    t = 'th'
    if x % 10 == 1 and x != 11: t = 'st'
    elif x % 10 == 2 and x != 12: t = 'nd'
    elif x % 10 == 3 and x != 13: t = 'rd'
    return f'{x}{t}'
