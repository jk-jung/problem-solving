def is_orthogonal(u, v): 
    return sum(x*y for x, y in zip(u, v)) == 0