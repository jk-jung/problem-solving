def you_are_a_cube(cube):
    a = int(cube ** (1 / 3))
    while a ** 3 < cube: a += 1
    return a ** 3 == cube
