from collections import Counter as C
def common(a,b,c):
    a, b, c = C(a), C(b), C(c)
    return sum(min(a[k], b[k], c[k]) * k for k in a)
