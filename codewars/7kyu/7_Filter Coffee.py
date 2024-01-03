def search(a, b):
    return ','.join([str(x) for x in sorted(b) if x <= a])
