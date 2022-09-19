def one_two_three():
    a = one_two() + one_two() - 1
    if a == 2 and one_two() == 2:
        return one_two_three()
    return a