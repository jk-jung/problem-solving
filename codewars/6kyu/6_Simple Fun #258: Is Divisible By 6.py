def is_divisible_by_6(s):
    t = sum(int(x) for x in s if x.isdigit())
    r = []
    for i in range(0, 10):
        if (t + i) % 3 == 0:
            r.append(str(i).join(s.split('*')))
    return [x.lstrip('0') or '0' for x in r if x[-1] in '02468']
