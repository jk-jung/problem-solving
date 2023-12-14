def Dragon(n):
    try:
        if n < 0: return ''
        r = 'Fa'
        for i in range(n):
            t = ''
            for x in r:
                if x == 'a':t += 'aRbFR'
                elif x == 'b': t += 'LFaLb'
                else: t += x
            r = t
        return r.replace('a', '').replace('b', '')
    except: return ''
