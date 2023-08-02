def solution(s, t):
    r = s * t
    for i in range(1, (t + 1) // 2 + 1):
        k = (t - i * 2 + 3) * s
        for j in range(i - 1):
            k += (s - j - 1) * 3
        if k == 11: print(i)
        r = max(r, k)
    return r
