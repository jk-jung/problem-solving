def on_line(points):
    points = list(set(points))
    if len(points) <= 2: return True
    x0, y0 = points[0]
    x1, y1 = points[1]
    for i in range(2, len(points)):
        xi, yi = points[i]
        if (yi - y0) * (x1 - x0) != (y1 - y0) * (xi - x0): return False
    return True
