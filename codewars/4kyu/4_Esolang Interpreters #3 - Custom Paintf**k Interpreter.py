def interpreter(code, n, w, h):
    r = [[0 for _ in range(w)] for _ in range(h)]
    code = [x for x in code if x in 'nesw*[]']

    jump, stack = {}, []
    for i, x in enumerate(code):
        if x == '[':
            stack.append((i, x))
        elif x == ']':
            j, y = stack.pop()
            jump[i] = j
            jump[j] = i

    x, y, i = 0, 0, 0
    for _ in range(n):
        c = code[i]
        last_i, last_c, last_v = i, c, r[y][x]
        if c == '*': r[y][x] ^= 1
        elif c == 's': y = (y + 1) % h
        elif c == 'n': y = (y + h - 1) % h
        elif c == 'e': x = (x + 1) % w
        elif c == 'w': x = (x + w - 1) % w
        elif c == '[' and r[y][x] == 0: i = jump[i]
        elif c == ']' and r[y][x] == 1: i = jump[i]
        i += 1
        if i == len(code):break

    return '\r\n'.join((''.join(str(x) for x in y)) for y in r)