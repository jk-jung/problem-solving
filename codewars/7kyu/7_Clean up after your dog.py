def crap(garden, bags, cap):
    s = ''.join(''.join(x) for x in garden)
    if 'D' in s: return 'Dog!!'
    return 'Clean' if s.count('@') <= bags * cap else 'Cr@p'
