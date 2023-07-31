def custom_sort(v):
    return sorted(v, key=lambda x: (x + chr(137) * 1000)[:1000])
