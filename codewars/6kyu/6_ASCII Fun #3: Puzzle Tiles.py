def puzzle_tiles(w, h):
    t = ['  ' + ' _( )__' * w]
    for i in range(h):
        if i % 2:
            t.append(' |_' + '     |_' * w)
            t.append('  _)' + ' _   _)' * w)
        else:
            t.append(' _|' + '     _|' * w)
            t.append('(_' + '   _ (_' * w)
        t.append(' |' + '__( )_|' * w)
    return '\n'.join(t)