def is_triangle_number(n):
    if type(n) != type(1):
        return False

    m = int((n * 2) ** .5)
    for i in range(1):
        i = m + i
        if i * (i + 1) // 2 == n:
            return True
    return False
