def is_kiss(w):
    w = w.split(' ')
    return "Good work Joe!" if max(map(len, w)) <= len(w) else "Keep It Simple Stupid"
