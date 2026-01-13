def sum_dif_rev(n):
    cnt = 0
    for i in range(10, 1000000):
        if i % 10 == 0:
            continue
        j = int(str(i)[::-1])
        if i != j and (i + j) % (i - j) == 0:
            cnt += 1
            if cnt == n:
                return i
