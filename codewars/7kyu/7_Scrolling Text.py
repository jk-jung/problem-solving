def scrolling_text(t):
    t = t.upper()
    return [t[i:] + t[:i] for i in range(len(t))]
