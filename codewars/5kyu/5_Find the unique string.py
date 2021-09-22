from collections import Counter
def find_uniq(v):
    v = [x + ' ' for x in v]
    c = Counter([tuple(set(x.lower())) for x in v]).most_common()[-1][0]
    return [x for x in v if tuple(set(x.lower())) == c][0][:-1]
