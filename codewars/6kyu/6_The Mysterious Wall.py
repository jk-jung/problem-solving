def build_a_wall(h=None, w=None):
    try:
        if h * w > 10000: return "Naah, too much...here's my resignation."
        s = '■■|' * (30 * w)
        r = [s[i % 2:3 * w + (1 if i % 2 else -1)] for i in range(0, h)]
        return '\n'.join(r[::-1]).strip() or None

    except: return
