def get_min_base(n):
    def f(k):
        s, e = 2, n
        while s <= e:
            m = (s + e) // 2
            t, c, cnt = 0, 1, 0
            while t < n:
                cnt += 1
                t += c
                c *= m
            if cnt < k:
                e = m - 1
            elif cnt > k:
                s = m + 1
            elif t > n:
                e = m - 1
            else:
                return m
        return -1
        
    for i in range(60, 1, -1):
        if (t := f(i)) != -1:
            return t
