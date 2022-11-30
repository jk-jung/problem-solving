v = sorted(VALID_WORDS, key=lambda x: -len(x))

def max_match(s):
    r, i = [], 0
    while i < len(s):
        ok = False
        for x in v:
            if s[i:].startswith(x):
                r.append(x)
                ok = True
                i += len(x)
                break
        if not ok:
            r.append(s[i])
            i += 1
    return r
