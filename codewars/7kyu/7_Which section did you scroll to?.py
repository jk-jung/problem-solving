def get_section_id(s, x):
    for i, y in enumerate(x):
        s -= y
        if s < 0: return i
    return -1
