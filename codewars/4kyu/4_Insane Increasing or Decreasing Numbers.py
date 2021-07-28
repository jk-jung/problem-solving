import numpy as np
from numpy.linalg import matrix_power

def insane_inc_or_dec(max_digits):
    x1 = np.zeros((11, 11), dtype=object)
    x2 = np.zeros((11, 11), dtype=object)
    r = np.ones(11, dtype=object)
    r[10] = r[0] = 0
    for i in range(10):
        for j in range(10):
            if i <= j: x1[i][j] = 1
            if i >= j: x2[i][j] = 1
        x1[i][10] = x2[i][10] = 1
        x1[10][10] = x2[10][10] = 1
    r1 = np.matmul(r, matrix_power(x1, max_digits))
    r2 = np.matmul(r, matrix_power(x2, max_digits))

    return (r1[10] + r2[10] - max_digits * 9 + 12345787) % 12345787
