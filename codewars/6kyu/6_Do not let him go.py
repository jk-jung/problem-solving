def locate_entrance(v):
    for i in range(len(v)):
        for j in range(len(v[i])):
            if v[i][j] != '.': continue
            for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                y, x = i + dy, j + dx
                try: t = v[y][x]
                except: t = ' '
                if t == ' ' or i == 0 or j == 0: return(j, i)

    return 0, 0
