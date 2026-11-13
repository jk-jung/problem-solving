def sc(s):
    
    return len(s) * 2 - 1 + 5 * len([x for x, y in zip(s, s[1:]) if x != y])