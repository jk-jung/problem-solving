from collections import Counter


def is_language_diverse(v):
    c = [x[1] for x in Counter(x['language'] for x in v).most_common()]
    return c[-1] * 2 >= c[0]