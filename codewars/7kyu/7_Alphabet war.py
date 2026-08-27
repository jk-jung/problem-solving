def alphabet_war(a):
    r = 0
    for x in a:
        if x == 'w':
            r += 4
        if x == 'p':
            r += 3
        if x == 'b':
            r += 2
        if x == 's':
            r += 1
        if x == 'm':
            r -= 4
        if x == 'q':
            r -= 3
        if x == 'd':
            r -= 2
        if x == 'z':
            r -= 1
    if r == 0:
        return "Let's fight again!"
    return "Left side wins!" if r > 0 else "Right side wins!"
