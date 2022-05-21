def find_children(t):
    t = sorted(t, key=lambda x: ord(x.lower()) * 2 if x.isupper() else ord(x) * 2 + 1)
    return ''.join(t)