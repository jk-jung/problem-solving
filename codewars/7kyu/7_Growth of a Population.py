def nb_year(p0, percent, aug, p):
    r = 0
    while p0<p:
        p0+=int(p0*(percent/100))+aug
        r+=1
    return r
