def wave(x):
    return [x[:i] + x[i].upper() + x[i + 1:] for i in range(len(x)) if x[i] != ' ']
