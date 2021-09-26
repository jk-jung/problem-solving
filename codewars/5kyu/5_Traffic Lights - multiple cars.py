def traffic_lights(road, n):
    map = ('G' * 5 + 'O' + 'R' * 5) * n
    time = {'G': 0, 'O': 5, 'R': 6}
    m = len(road)

    r = [_ for _ in road]
    rr = [road]
    for t in range(1, n+1):
        st = ''
        nt = ['.' for _ in range(m)]
        for i in range(m - 1, -1, -1):
            if road[i] in 'GOR':
                st = map[time[road[i]] + t]
                nt[i] = st
            if r[i] == 'C':
                if i == m - 1: pass
                elif nt[i + 1] in '.':
                    nt[i+1] = 'C'
                elif nt[i + 1] in 'G' and (i + 2 == m or nt[i+2] == '.'):
                    nt[i+1] = 'C'
                else:
                    nt[i] = 'C'
        r = nt
        rr.append(''.join(r))
    return rr