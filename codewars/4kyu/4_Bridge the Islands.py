import numpy as np
def bridge(v):
    r, n = 0, len(v)

    vv = np.array(v)
    dd = np.linalg.norm(vv[:, None, :] - vv[None, :, :], axis=-1)

    d = dd[0]
    vis = [0 for i in range(n)]
    vis[0] = 1
    s = {i for i in range(n) if i != 0}
    for _ in range(n - 1):
        k = min(s, key=lambda x: d[x])
        r += d[k]
        s.remove(k)
        d = np.minimum(d, dd[k])
    return r