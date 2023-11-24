from preloaded import vector_length as f

def point_in_vector(a, v):
    return abs(f(v) - f([v[0], a]) - f([v[1], a])) < 1e-9
