def draw(v):
    r = []
    for i in range(0, max(v)):
        r.append(''.join('■' if x > i else '□' for x in v))
    return '\n'.join(r[::-1])
