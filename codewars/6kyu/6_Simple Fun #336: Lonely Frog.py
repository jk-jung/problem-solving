def jump_to(n):
    s, n = 0, abs(n)
    for i in range(100000):
        s += i
        if s >= n and (s - n) % 2 == 0: return i
