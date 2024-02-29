def could_be(a, b):
    if not a.strip() or not b.strip(): return False
    a = set(a.split())
    b = set(b.split())
    return a & b == b
