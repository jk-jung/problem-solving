def mobile_display(w, p):
    w = max(20, w)
    p = max(30, p)
    h = w * p // 100

    r = []
    for i in range(h):
        if i == 0 or i == h - 1:
            r.append('*' * w)
        elif i == h // 2 - 1:

            r.append('*' + 'sraWedoC'.center(w - 2)[::-1] + '*')
        elif i == h - 2:
            r.append('* Menu' + ' ' * (w - 16) + 'Contacts *')
        else:
            r.append('*' + ' ' * (w - 2) + '*')

    return '\n'.join(r)
