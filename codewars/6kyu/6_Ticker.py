def ticker(s, w, t):
    s = s + ' ' * w
    s = ' ' * w + s * (t + 1)
    return s[t:t + w]
