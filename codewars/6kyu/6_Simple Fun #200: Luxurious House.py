def luxhouse(h):
    return [max(0, max(h[i + 1:] + [0]) + 1 - x) for i, x in enumerate(h)]
