# Your new function as given to you by me, your boss.
def cut_log(p, n):
    d = [0 for _ in range(n + 1)]
    for j in range(1, n + 1):
        for i in range(1, j + 1):  # Two nested loops = Θ(n^2)
            for k in range(1, len(p)):
                if i >= k:
                    d[j] = max(d[j], d[i - k] + p[k])
    return d[-1]
