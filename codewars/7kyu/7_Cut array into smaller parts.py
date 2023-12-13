def make_parts(arr, chunk_size):
    return [arr[i: i+chunk_size] for i in range(0,len(arr),chunk_size)]
