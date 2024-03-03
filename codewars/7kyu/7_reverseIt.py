def reverse_it(data):
    if isinstance(data, bool): return data
    if isinstance(data, int): return int(str(data)[::-1])
    if isinstance(data, float): return float(str(data)[::-1])
    if isinstance(data, str): return data[::-1]
    return data
