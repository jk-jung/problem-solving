def compare_versions(v1, v2):
    v1 = [int(x) for x in v1.split('.')]
    v2 = [int(x) for x in v2.split('.')]

    while v1 and v2:
        x = v1.pop(0)
        y = v2.pop(0)
        if x < y:
            return False
    return False if v2 else True