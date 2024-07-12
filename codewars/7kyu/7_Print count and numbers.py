from itertools import groupby
def count_me(s):
    if not s.isdigit():return ''
    r = ''
    for k, v in groupby(s):
        r += f"{len(list(v))}{k}"

    return r
