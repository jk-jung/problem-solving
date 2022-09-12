def findSquares(x, y):
    return sum((x - i) * (y - i) for i in range(min(x, y)))
