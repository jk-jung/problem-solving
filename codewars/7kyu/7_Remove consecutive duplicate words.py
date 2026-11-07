def remove_consecutive_duplicates(s) -> str:
    r = []
    for x in s.split(' '):
        if not r or r[-1] != x:
            r.append(x)
    return ' '.join(r)