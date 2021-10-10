def to_postfix(s):
    pr = {
        '(': 4, ')': 4,
        '^': 1,
        '/': 2, '*': 2,
        '+': 3, '-': 3
    }

    num, op = [], []

    def pop():
        b, a = num.pop(), num.pop()
        num.append(a + b + op.pop())

    for x in s:
        if x == '(':
            op.append(x)
        elif x == ')':
            while op[-1] != '(': pop()
            op.pop()
        elif x in pr:
            while len(op) > 0 and pr[op[-1]] <= pr[x]:
                if op[-1] == '^' and x == '^': break
                pop()
            op.append(x)
        else:
            num.append(x)

    while len(op) > 0: pop()

    return num[0]
