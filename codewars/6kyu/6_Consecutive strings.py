def longest_consec(v, k):
    if k <= 0 or k > len(v): return ''
    return max([''.join(v[i:i + k]) for i in range(0, len(v) - k + 1)], key=lambda x: len(x))