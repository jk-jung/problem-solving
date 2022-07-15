def next_higher(x):
    cnt = 0
    for i in range(300):
        if (x >> i & 1) == 0:
            if cnt:
                x ^= (1 << i)
                x ^= (1 << (cnt - 1)) - 1
                return x
        else:
            x ^= (1 << i)
            cnt += 1
    return x
