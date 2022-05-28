def dont_give_me_five(start, end):
    def calc(y, up):
        sign = -1 if y < 0 else 1
        x = str(abs(y))
        r = 0
        flag = False
        for t in x:
            d = int(t)
            r *= 9
            if d == 5:
                d = 6
            if not flag:
                r += (d if d < 5 else d - 1)
            if t == '5':
                flag = True
        if (sign == 1 and up and flag) or (sign == -1 and not up and flag):
            r -= 1
        return r * sign

    s = calc(start, False)
    e = calc(end, True)

    return e - s + 1