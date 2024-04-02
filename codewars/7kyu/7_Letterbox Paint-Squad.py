from collections import Counter
def paint_letterboxes(s, e):
    return [Counter(''.join(map(str, range(s, e+1))))[str(x)] for x in range(10)]
