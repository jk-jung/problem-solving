def nth_root_equals_digit_sum(n):
    r = [1]
    for i in range(2, 1000):
        k = i ** n
        if sum(map(int, str(k))) == i:
            r.append(k)
    return r
