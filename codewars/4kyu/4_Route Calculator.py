def calculate(exp):
    postfix = []
    ops = []
    pr = {'+': 0, '-': 0, '*': 1, '$': 1}

    i = 0
    while i < len(exp):
        x = exp[i]
        if x not in '.0123456789+-*$': return '400: Bad request'

        if x in '.0123456789':
            n = ''
            while i < len(exp) and exp[i] in '.0123456789':
                n += exp[i]
                i += 1
            i -= 1
            postfix.append(float(n))
        else:
            while len(ops) > 0 and pr[ops[-1]] >= pr[x]:
                postfix.append(ops.pop())
            ops.append(x)
        i += 1
    while len(ops) > 0:
        postfix.append(ops.pop())

    r = []
    for x in postfix:
        if x == '+':
            r.append(r.pop() + r.pop())
        elif x == '-':
            r.append(-r.pop() + r.pop())
        elif x == '*':
            r.append(r.pop() * r.pop())
        elif x == '$':
            r.append(1 / r.pop() * r.pop())
        else:
            r.append(float(x))

    return r[0]
