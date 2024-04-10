def game(a, b):
    if a <= 0 or b <= 0: return "Non-drinkers can't play"

    c = 1
    while True:
        a -= c
        if a < 0: return 'Joe'
        c += 1
        b -= c
        if b < 0: return "Mike"
        c += 1
