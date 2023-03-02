def to_table(data, header=False, index=False):
    if index:
        if header:
            data[0].insert(0, '')
        for i, x in enumerate(data[1:] if header else data):
            x.insert(0, i + 1)
    r = ''
    def f(x): return '' if x is None else x
    if header:
        r += f"<thead><tr>{''.join(f'<th>{f(x)}</th>' for x in data[0])}</tr></thead>"
        data = data[1:]
    k = ''
    for y in data:
        k += f"<tr>{''.join(f'<td>{f(x)}</td>' for x in y)}</tr>"

    r += f"<tbody>{k}</tbody>"
    return f"<table>{r}</table>"
