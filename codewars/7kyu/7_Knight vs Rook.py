def knight_vs_rook(a, b):
    x = abs(a[0] - b[0])
    y = abs(ord(a[1]) - ord(b[1]))

    if x * y == 0:
        return "Rook"
    if x * y > 0 and x + y == 3:
        return "Knight"
    return "None"
