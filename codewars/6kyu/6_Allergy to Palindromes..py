def count_pal(n):
    r = [9]
    for i in range(2, n + 1):
        if i % 2: r.append(r[-1] * 10)
        else: r.append(r[-1])
    # amount of digits
    # your code here
    return [r[-1], sum(r)]
