from math import comb
def travel_chessboard(s):
    x = list(map(int, s.replace('(', ' ').replace(')', ' ').split()))
    a = x[2] - x[0]
    b = x[3] - x[1]
    return comb(a + b, a)
