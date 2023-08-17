import numpy as np
def weather_prediction(n, a, b, P):
    v = np.array(P)
    t = np.array(P)
    for i in range(n - 1): v = v @ t
    return v[a][b]
