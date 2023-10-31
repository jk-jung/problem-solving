def has_two_cube_sums(n):
    r = 0
    for i in range(1, int(n ** (1 / 3)) + 1):
        t = n - i ** 3
        k = int(t ** (1 / 3))
        while k ** 3 < t:k += 1
        if i <= k and k ** 3 == t:
            r += 1
    return r >= 2