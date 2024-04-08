def solve(a,b):
    return ''.join([x for x in a if x not in b]) +  ''.join([x for x in b if x not in a])
