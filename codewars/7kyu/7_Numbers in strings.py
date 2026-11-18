def solve(s):
    s = ''.join([x if x.isdigit() else ' ' for x in s]).split(' ')
    return max([int(x) for x in s if x])