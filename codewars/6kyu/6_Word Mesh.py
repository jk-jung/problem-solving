def word_mesh(w):
    r = ''
    for i in range(0, len(w) - 1):
        ok = False
        for j in range(0, len(w[i])):
            x = w[i][j:]
            if w[i + 1].startswith(x):
                r += x
                ok = True
                break
        if not ok: return 'failed to mesh'
    return r
