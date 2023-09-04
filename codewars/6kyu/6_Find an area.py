def find_area(v):
    return sum((y.X - x.X) * (y.Y + x.Y) / 2 for x, y in zip(v, v[1:]))
