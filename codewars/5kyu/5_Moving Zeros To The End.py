def move_zeros(array):
    return [x for x in array if x != 0] +  [x for x in array if x == 0]