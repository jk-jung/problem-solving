def one(xs, f): 
    return len([x for x in xs if f(x)]) == 1