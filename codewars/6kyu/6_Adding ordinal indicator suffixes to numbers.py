def number_to_ordinal(n):
    n = str(n)
    if n == '0': return n
    if n[-2:] in ('11', '12', '13'): return n + 'th'
    return n + {'1': 'st', '2': 'nd', '3': 'rd'}.get(n[-1], 'th')
