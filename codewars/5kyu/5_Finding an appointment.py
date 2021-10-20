def get_start_time(sc, duration):
    def nonoverlap(a, s):
        for i in range(duration):
            x = '%02d:%02d' % ((a + i) // 60, (a + i) % 60)
            if s[0] <= x < s[1]: return False
        return True

    for i in range(9 * 60, 19 * 60 - duration + 1):
        x = '%02d:%02d' % (i // 60, i % 60)
        t = all(all([nonoverlap(i, s) for s in ss]) for ss in sc)
        if t: return x

    return
