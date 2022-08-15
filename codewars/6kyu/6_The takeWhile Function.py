def take_while(arr, pred_fun):
    r = [x if pred_fun(x) else None for x in arr] + [None]
    return r[:r.index(None)]
