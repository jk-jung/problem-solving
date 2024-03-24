def even_numbers(arr,n):
    return [x for x in arr if x % 2 == 0][-n:]
