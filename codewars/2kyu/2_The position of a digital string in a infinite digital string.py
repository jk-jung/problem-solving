def get_pos(x):
    x = x - 1
    base, t, r = 1, 1, 0
    while base * 10 <= x:
        r += t * (base * 9)
        base *= 10
        t += 1
    return r + t * (x - base + 1)


def can(s, x, pos):
    if str(int(x)) != x: return False
    t = x[pos:]
    while len(t) < len(s):
        x = str(int(x) + 1)
        t += x
    return s == t[:len(s)]


def prev(x):
    if x == '': return '100000'
    return str(int(x) - 1)


def check(s, num, pos):
    front = s[:num - pos]
    back = s[num - pos:]
    r = ['9' * 1000]

    if pos == 0 and front[0] == '0': return -1
    if len(back) > 0 and back[0] == '0': return -1
    if len(back) < pos:
        t = front
        if pos > 0: t = '1' + '0' * (pos - 1) + t
        if can(s, t, pos): r.append(t)
    else:
        ts = [
            back[:pos] + front,
            prev(back[:pos]) + front,
            '9' * num
        ]
        r += [k for k in ts if can(s, k, pos)]

    x = min(r)
    if len(x) >= 1000: return -1
    return get_pos(int(x)) + pos


def find_position(s):
    for i in range(1, len(s) + 2):
        r = [check(s, i, j) for j in range(i)]
        r = sorted([x for x in r if x != -1])
        if len(r) > 0: return r[0]
