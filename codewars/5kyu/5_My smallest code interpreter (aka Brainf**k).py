def brain_luck(code, program_input):
    program_input = list(program_input)
    data = [0 for _ in range(100000)]
    pt = 0

    r = ''

    to, fr, op = {}, {}, []
    for i, x in enumerate(code):
        if x == '[': op.append(i)
        elif x == ']':
            to[op[-1]] = i
            fr[i] = op.pop()

    i = 0

    while i < len(code):
        x = code[i]

        if x == ',': data[pt] = ord(program_input.pop(0))
        elif x == '.': r += chr(data[pt])
        elif x == '+': data[pt] = (data[pt] + 1) % 256
        elif x == '-': data[pt] = (data[pt] + 255) % 256
        elif x == '[' and data[pt] == 0: i = to[i]
        elif x == ']' and data[pt] != 0: i = fr[i]
        elif x == '<': pt -= 1
        elif x == '>': pt += 1

        i += 1
    return r