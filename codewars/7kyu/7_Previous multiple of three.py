def prev_mult_of_three(n):
    while n:
        if n % 3 == 0: return n
        n //= 10
    return None
