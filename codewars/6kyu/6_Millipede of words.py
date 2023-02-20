from itertools import permutations
def solution(v):
    for x in permutations(v):
        ok = True
        for i in range(1, len(v)):
            if x[i - 1][-1] != x[i][0]:
                ok = False
        if ok:
            return True
    return False
