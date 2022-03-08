from collections import Counter


def delete_nth(v, m):
    cnt = Counter()
    def ck(x):
        cnt[x] += 1
        return cnt[x] <= m
    return [x for x in v if ck(x)]
