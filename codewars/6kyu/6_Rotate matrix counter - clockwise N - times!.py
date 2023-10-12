import numpy as np
def rotate_against_clockwise(v, n):
    v = np.array(v)
    for i in range(n % 4):
        v = np.rot90(v)
    return v.tolist()
