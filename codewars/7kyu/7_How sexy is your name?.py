def sexy_name(name):
    score = sum([SCORES.get(x, 0) for x in name.upper()])

    if score <= 60: return  'NOT TOO SEXY'
    if 61 <= score <= 300:return'PRETTY SEXY'
    if 301 <= score <= 599:return'VERY SEXY'
    if score >= 600:return'THE ULTIMATE SEXIEST'
