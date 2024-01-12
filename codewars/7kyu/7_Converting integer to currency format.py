def to_currency(s):
    s = str(s)
    return ','.join(s[::-1][i:i+3] for i in range(0, len(s), 3))[::-1]
