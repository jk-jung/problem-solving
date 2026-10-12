def div_con(x):
    return sum([i for i in x if isinstance(i, int)]) - sum([int(i) for i in x if isinstance(i, str)]) 
