import re

pair = {
    '+': '-',
    '-': '+',
    '[': ']',
    '<': '>',
    '>': '<',
}
def brainfuck_to_c(s):
    s = re.sub('[^+-<>,.\[\]]', '', s)
    r = []
    for x in s:
        if r and pair.get(r[-1]) == x:
            r.pop()
        else:
            r.append(x)
            
    n, i, s, d = len(r), 0, "", 0
    while i < n:
        x = r[i]
        if x in '+-':
            c = 0
            while i < n and r[i] in '+-':
                c += 1
                i += 1
            s += d * ' ' + f"*p {x}= {c};\n"
            i -= 1
        elif x in '<>':
            c = 0
            while i < n and r[i] in '<>':
                c += 1
                i += 1
            s += d * ' ' + f"p {'+' if x == '>' else '-'}= {c};\n"
            i -= 1
        elif x == '.':
            s += d * ' ' + "putchar(*p);\n"
        elif x == ',':
            s += d * ' ' + "*p = getchar();\n"
        elif x == '[':
            s += d * ' ' + "if (*p) do {\n"
            d += 2
        elif x == ']':
            d -= 2
            s += d * ' ' + "} while (*p);\n"
            if d < 0:
                return 'Error!'
        i += 1
        
    if d:
        return 'Error!'

    return s
