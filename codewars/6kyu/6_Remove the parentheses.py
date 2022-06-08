def remove_parentheses(s):
    r, t = '', 0
    for x in s:
        if x == '(': t += 1
        elif x == ')': t -= 1
        elif t == 0: r += x
    return r