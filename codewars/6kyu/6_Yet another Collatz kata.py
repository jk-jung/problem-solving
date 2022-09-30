def collatz():
    q = [1]
    vis = {1}
    while True:
        nq = set()
        for x in q:
            yield x
            t = (x - 1) // 3
            if x > 1 and (x - 1) % 3 == 0 and t % 2 == 1 and t not in vis:
                nq.add(t)
            nq.add(x * 2)
        vis |= nq
        q = sorted(nq)
