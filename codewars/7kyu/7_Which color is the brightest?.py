def brightest(colors):
    return max(colors, key=lambda x: max(x[1:3], x[3:5], x[5:]))
