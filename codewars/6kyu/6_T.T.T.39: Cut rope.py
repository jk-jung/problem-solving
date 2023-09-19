from collections import Counter
def cut_rope(l, m, n):
    a = sorted(set(range(0, l, m)) | set(range(0, l, n)) | {l})
    c = Counter([y - x for x, y in zip(a, a[1:])])
    return {f'{k}cm': v for k, v in c.items()}
