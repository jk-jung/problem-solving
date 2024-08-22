from collections import Counter
def compare(a, b):
    a = Counter(str(a))
    b = Counter(str(b))
    if not a & b: return '0%'
    if a == b: return '100%'
    return '50%'
