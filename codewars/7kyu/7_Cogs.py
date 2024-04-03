def cog_RPM(cogs):
    r = cogs[0]
    t = -1
    for x in cogs:
        t *= -r / x
        r = x
    return t
