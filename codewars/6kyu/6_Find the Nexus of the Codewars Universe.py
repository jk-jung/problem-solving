def nexus(u):
    return sorted([x for x in u.items()], key=lambda x: (abs(x[0] - x[1]), x[0]))[0][0]