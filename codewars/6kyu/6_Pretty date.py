def to_pretty(s):
    if s == 0: return 'just now'
    t = [
        (60, 1, 'second', 'a'),
        (3600, 60, 'minute', 'a'),
        (3600 * 24, 3600, 'hour', 'an'),
        (3600 * 24 * 7, 3600 * 24, 'day', 'a'),
        (3600 * 24 * 7 * 333, 3600 * 24 * 7, 'week', 'a'),
    ]
    for x in t:
        if s < x[0]:
            k = s // x[1]
            return f"{x[-1] if k == 1 else k} {x[2]}{'' if k == 1 else 's'} ago"
