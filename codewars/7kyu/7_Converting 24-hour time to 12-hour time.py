def to_12_hour_time(t):
    h, m = int(t[:2]), t[2:]
    if h < 12:
        return f"{12 if h == 0 else h}:{m:02} am"
    return f"{12 if h == 12 else h - 12}:{m:02} pm"
