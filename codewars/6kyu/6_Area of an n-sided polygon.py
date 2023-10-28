import numpy as np
def area_polygon(v):
    x = np.array([a[0] for a in v])
    y = np.array([a[1] for a in v])
    return round(0.5*np.abs(np.dot(x,np.roll(y,1))-np.dot(y,np.roll(x,1))), 1)
