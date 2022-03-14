def sum_dig_pow(a, b): # range(a, b + 1) will be studied by the function
    def f(x):
        r, i = 0, 0
        x = int(str(x)[::-1])
        while x:
            i += 1
            r += (x % 10) ** i
            x //= 10
        return r

    return [x for x in range(a, b + 1) if f(x) == x]