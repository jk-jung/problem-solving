from collections import defaultdict
def switch_dict(dic):
    r = defaultdict(list)
    for k, v in dic.items():
        r[v].append(k)
    return r
