def parse_html_color(c):
    if c.lower() in PRESET_COLORS: c = PRESET_COLORS[c.lower()]
    if len(c) == 4: c = ''.join(''.join(x) for x in zip(c, c))[1:]
    return {
        'r': int(c[1:3], 16),
        'g': int(c[3:5], 16),
        'b': int(c[5:7], 16),
    }
