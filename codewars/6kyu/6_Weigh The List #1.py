def weigh_the_list(a):
    return [x * (-1 if i < len(a) // 2 else 1) for i, x in enumerate(a[::-1])]
