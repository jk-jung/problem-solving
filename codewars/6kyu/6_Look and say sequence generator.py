from itertools import groupby


def look_and_say_sequence(x, n):
    for i in range(1, n):
        x = ''.join(str(len(list(v))) + str(k) for k, v in groupby(x))
    return x