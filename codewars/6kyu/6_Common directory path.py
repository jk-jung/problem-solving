import os

def get_common_directory_path(v):
    r = ''
    for i in range(len(v[0])):
        t = { x[:i] for x in v}
        if len(t) == 1:
            r = list(t)[0]
    r = os.path.dirname(r + 'a')
    if r == '': return r
    if r[-1] != '/': r += '/'
    return r
