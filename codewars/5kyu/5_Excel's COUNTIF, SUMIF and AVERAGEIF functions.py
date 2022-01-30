def f(v, c):
    if isinstance(c, str) and c[0] in '<>':
        if '>=' in c: return [x for x in v if x >= float(c[2:])]
        if '<=' in c: return [x for x in v if x <= float(c[2:])]
        if '<>' in c: return [x for x in v if x != float(c[2:])]
        if '>' in c: return [x for x in v if x > float(c[1:])]
        if '<' in c: return [x for x in v if x < float(c[1:])]
    else:
        return [x for x in v if x == c]

def count_if(v, c):
    return len(f(v, c))

def sum_if(v, c):
    return sum(f(v, c))

def average_if(v, c):
    return sum(f(v, c)) / len(f(v, c))