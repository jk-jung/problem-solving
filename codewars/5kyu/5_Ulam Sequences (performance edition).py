def ulam_sequence(u0, u1, n):
    r = [u0, u1]
    ok = {u0 + u1}
    used = {u0, u1}

    for i in range(2, n):
        x = sorted(ok)[0]
        ok.remove(x)

        for y in r:
            z = x + y
            if z in used: continue
            elif z in ok:
                ok.remove(z)
                used.add(z)
            else:
                ok.add(z)

        r.append(x)

    return r