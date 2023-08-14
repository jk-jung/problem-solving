def make_password(length, flag_upper, flag_lower, flag_digit):
    r = ''
    if flag_upper: r += 'A'
    if flag_lower: r += 'a'
    if flag_digit: r += '0'
    for i in range(255):
        x = chr(i)
        if not flag_upper and x.isupper(): continue
        if not flag_lower and x.islower(): continue
        if not flag_digit and x.isdigit(): continue
        if x.isalnum() and len(r) < length and x not in r:
            r += x
    return r
