import numpy as np
def getMatrixProduct(a, b):
    a, b = np.asarray(a), np.asarray(b)
    try: return (a @ b).tolist()
    except: return -1
