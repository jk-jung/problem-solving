def meeting(rooms, need):
    r = []
    for a, b in rooms:
        if need == 0: break
        k = min(need, max(0, b - a.count('X')))
        need -= k
        r.append(k)

    if not r: return 'Game On'
    if need == 0: return r
    return "Not enough!"
