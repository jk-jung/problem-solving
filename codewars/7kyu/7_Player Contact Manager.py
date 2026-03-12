def player_manager(a):
    r = []
    if not a:
        return r
    t = a.split(", ")
    for i in range(0, len(t), 2):
        x, y = t[i : i + 2]
        r.append({"player": x, "contact": int(y)})
    return r
