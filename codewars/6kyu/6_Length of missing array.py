def get_length_of_missing_array(a):
    try:
        s = min(len(x) for x in a)
        if s == 0:
            return 0
        for i in range(s, s + len(a) + 10):
            if all(len(x) != i for x in a):
                return i
    except:
        pass
    return 0