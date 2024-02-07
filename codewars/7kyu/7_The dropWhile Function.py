def drop_while(arr, pred):
    while arr and pred(arr[0]):arr.pop(0)
    return arr
