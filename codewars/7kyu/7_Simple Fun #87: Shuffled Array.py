def shuffled_array(s):
    for i, x in enumerate(s):
        if sum(s) == x * 2:
            return sorted(s[:i] + s[i+1:])
