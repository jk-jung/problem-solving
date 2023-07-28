def press_button(n):
    r = 0
    for i in range(n):
        for j in range(n - i):
            if j:
                r += i
            r += 1
    return r
