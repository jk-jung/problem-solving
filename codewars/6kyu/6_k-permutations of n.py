from itertools import permutations


def k_permutations_of_n(lst, k):
    return [list(x) for x in permutations(lst, k)]
