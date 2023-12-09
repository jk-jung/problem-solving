def getVertex(a,b,c):
    h = b / (-2 * a)
    k = c - h * h * a
    return [h, k]
