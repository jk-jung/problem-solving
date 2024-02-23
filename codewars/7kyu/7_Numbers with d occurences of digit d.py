from collections import Counter
def is_dd(n):
    return any(int(k) == v for k, v in Counter(str(n)).items())
