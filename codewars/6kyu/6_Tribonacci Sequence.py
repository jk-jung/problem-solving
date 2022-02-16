def tribonacci(v, n):
    while len(v) < n: v.append(v[-1] + v[-2] + v[-3])
    return v[:n]