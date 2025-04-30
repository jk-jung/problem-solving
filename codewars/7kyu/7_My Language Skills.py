def my_languages(r):
    return [x[1] for x in sorted([(-v, k) for k, v in r.items() if v > 59])]