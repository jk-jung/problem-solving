def amount_of_pages(n):
    r, m, c = 0, 1, 1
    while n:
        if n <= 9 * m * c:
            return  m + n // c - 1
        n -= 9 * m * c
        c += 1
        m *= 10
