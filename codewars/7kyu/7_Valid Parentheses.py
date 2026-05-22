def valid_parentheses(a):
    s = 0
    for x in a:
        if x == '(':
            s += 1
        else:
            s -= 1
            if s < 0:
                return False
    return s == 0
