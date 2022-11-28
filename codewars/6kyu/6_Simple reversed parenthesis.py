def solve(s):
    if len(s) % 2: return -1
    r, st = 0, 0
    for x in s:
        if x == '(': st += 1
        elif st == 0:
            r += 1
            st += 1
        else: st -= 1
    return r + st // 2
