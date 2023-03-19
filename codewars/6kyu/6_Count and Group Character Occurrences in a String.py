from collections import Counter, defaultdict
def get_char_count(s):
    c = Counter(x for x in s.lower() if x.isalnum())
    r = defaultdict(list)
    for k, v in c.items():
        r[v].append(k)
    for x in r.values():x.sort()
    return r
