from itertools import groupby
def sum_groups(v):
    while len(t:=list(groupby(v, key=lambda x: x % 2))) != len(v):
        v = [sum(x[1]) for x in groupby(v, lambda x: x % 2)]
    return len(v)
    #your code here
