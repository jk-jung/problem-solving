def my_very_own_split(string, d = None):
    od = d
    assert d != ''
    if d is None: d = [' ', '\t', '\n']
    else: d = [d]
    s = ''
    for x in string:
        s += x
        for y in d:
            if y in s:
                s = s[:-len(y)]
                if od is None and s == '': continue
                yield s
                s = ''
                break
    yield s