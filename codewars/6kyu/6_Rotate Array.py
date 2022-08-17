def rotate(data, n):
    if not data: return data
    n = n % len(data)
    return data[-n:] + data[:-n]
