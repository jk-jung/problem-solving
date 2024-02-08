def collision(x1, y1, r1, x2, y2, r2):
    t = (x1-x2)**2 + (y1-y2)**2
    return t <= (r1+r2)**2
