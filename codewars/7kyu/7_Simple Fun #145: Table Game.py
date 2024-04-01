def table_game(a):
    x, b, c, d = a[0][0], a[0][2], a[2][0], a[2][2]
    if x + b != a[0][1]: return [-1]
    if x + c != a[1][0]: return [-1]
    if b + d != a[1][2]: return [-1]
    if c + d != a[2][1]: return [-1]
    if x + b + c + d != a[1][1]: return [-1]
    return [x, b, c, d]
