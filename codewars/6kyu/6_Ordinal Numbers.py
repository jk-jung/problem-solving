def ordinal(n, b=False):
    if n == True: n = 1
    elif n == False: n = 0
    n = str(n)

    if n.endswith('1') and not n.endswith('11'):
        return 'st'
    if n.endswith('2') and not n.endswith('12'):
        return 'd' if b else 'nd'
    if n.endswith('3') and not n.endswith('13'):
        return 'd' if b else 'rd'
    return 'th'