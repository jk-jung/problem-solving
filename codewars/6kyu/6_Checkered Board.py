def checkered_board(n):
    try:
        if n <= 1: return False
    except:
        return False
    r = ''
    for i in range(n):
        for j in range(n):
            r += '□ ' if (i + j) % 2 == n % 2 else '■ '
        r = r.strip()
        r += '\n'
    return r.strip()
