def sort_me(v):
    return sorted(v, key=lambda x: x.split('-')[::-1])