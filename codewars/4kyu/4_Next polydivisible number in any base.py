nums = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'


def can(r, base):
    n, s = len(r), 0
    for x in r:
        s = (s * base + nums.index(x)) % n
    return s == 0


def go(idx, base, n, same, cur):
    if idx == len(n):
        return cur if not same else None

    start = nums.index(n[idx]) if same else 0
    if start == 0 and idx == 0 and len(n) > 1: start = 1

    for i in range(start, base):
        if not can(cur + nums[i], base): continue

        nxt_same = same and start == i
        r = go(idx + 1, base, n, nxt_same, cur + nums[i])
        if r: return r

    return None


def next_num(base, n):
    r = go(0, base, n, True, '')
    if r is None:
        r = go(0, base, '0' + '0' * len(n), False, '')
    return r
