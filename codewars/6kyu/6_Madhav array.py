def is_madhav_array(arr):
    n = len(arr)
    if n == 0 or n == 1:
        return False
    i = 1
    sum_so_far = arr[0]
    while i*(i+1)//2 < n:
        t = arr[i*(i+1)//2 : (i+1)*(i+2)//2]
        curr_sum = sum(arr[i*(i+1)//2 : (i+1)*(i+2)//2])
        if curr_sum != sum_so_far:
            return False
        sum_so_far = curr_sum
        i += 1
        if len(t) != i: return False
    return True
