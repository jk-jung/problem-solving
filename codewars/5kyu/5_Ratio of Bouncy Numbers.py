def bouncy_ratio(percent):
    def ck(n):
        a, b = False, False
        y = None
        while n:
            x = n % 10
            n //= 10
            if y is not None:
                if x < y: a = True
                if x > y: b = True
            y = x
        return a and b
    tot, cnt, i = 0, 0, 0

    while True:
        i += 1
        tot += 1
        if ck(i): cnt += 1
        if cnt / tot >= percent: return i
