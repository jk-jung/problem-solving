import math
def routes(n):
    if n<=0:
        return 0
    return math.comb(n*2,n)
