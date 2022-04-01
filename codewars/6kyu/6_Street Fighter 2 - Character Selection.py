def street_fighter_selection(v, pos, moves):
    pos = list(pos)
    r = []
    for x in moves:
        if x == "up": pos[0] -= 1
        if x == "down": pos[0] += 1
        if x == "right": pos[1] += 1
        if x == "left": pos[1] -= 1
        if pos[0] < 0: pos[0] = 0
        if pos[0] == len(v): pos[0] = len(v) - 1
        r.append(v[pos[0] % len(v)][pos[1] % len(v[0])])

    return r