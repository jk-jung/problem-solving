def the_janitor(w):
    r = []
    for i in range(26):
        x = chr(ord('a') + i)
        s, e = w.find(x), w.rfind(x)
        r.append(e - s + 1 if s != -1 else 0)
    return r
