def solution(a):
    ck = [0 for _ in range(len(a))]
    s = 0
    cnt = 0
    while True:
        ck[s] = 1
        s += a[s]
        cnt += 1
        if s < 0 or s >= len(a):
            return cnt
        if ck[s]:
            return -1
