def is_int_array(arr):
    try:
        return type(arr) == type([]) and all(int(x) == x for x in arr)
    except:
        return False