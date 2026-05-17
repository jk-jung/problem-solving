def cog_RPM(cogs, n):
    r = []
    for i, x in enumerate(cogs):
        r.append(cogs[n] / x * (-1 if (n - i) % 2 else 1))
    return [r[0], r[-1]]