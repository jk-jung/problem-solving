def sel_reverse(v,l):
    return sum([v[i: i + l][::-1] for i in range(0, len(v), l)], []) if l else v