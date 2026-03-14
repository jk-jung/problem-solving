def merge_strings(a, b):
    r = 0
    for i in range(len(a) + 1):
        if a[-i:] == b[:i]:
            r = i
    return a + b[r:]
