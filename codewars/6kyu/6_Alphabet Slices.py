def solution(s):
    r = []
    for x in s:
        if not r: r.append(x)
        elif ord(r[-1][-1]) + 1 == ord(x):r[-1] += x
        else: r.append(x)
    return ''.join(x[::-1] for x in r)
