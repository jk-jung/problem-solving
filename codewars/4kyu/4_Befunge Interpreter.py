import random


def interpret(code):
    vv = code.split('\n')
    n = len(code)
    m = len(code[0])
    v = [[x for x in y] for y in vv]

    output = ""
    st = [0] * 5
    y, x = 0, 0

    dd = {
        '>': [0, 1],
        'v': [1, 0],
        '<': [0, -1],
        '^': [-1, 0],
    }
    di = '>'
    mode = False
    skip = False

    while True:
        k = v[y][x]

        if k == '"':
            mode = not mode
        elif mode:
            st.append(ord(k))
        elif skip:
            skip = False
        elif k == '#':
            skip = True
        elif '0' <= k and k <= '9':
            st.append(ord(k) - ord('0'))
        elif k in ['+', '-', '*', '/', '%', '`']:
            a = st.pop(-1)
            b = st.pop(-1)
            if k == '+': c = a + b
            if k == '-': c = b - a
            if k == '*': c = a * b
            if k == '/': c = b // a if a != 0 else 0
            if k == '%': c = b % a if a != 0 else 0
            if k == '`': c = 1 if b > a else 0
            st.append(c)
        elif k == '!':
            a = st.pop(-1)
            st.append(1 if a == 0 else 0)
        elif k in '><v^':
            di = k
        elif k == '?':
            di = random.sample(dd.keys(), 1)[0]
        elif k in '|_':
            a = 0 if st.pop(-1) == 0 else 2
            a += 1 if k == '|' else 0
            di = list(dd.keys())[a]
        elif k == ':':
            st.append(st[-1])
        elif k == '\\':
            t = st[-1]
            st[-1] = st[-2]
            st[-2] = t
        elif k == '$':
            st.pop(-1)
        elif k == '.':
            output += str(st.pop(-1))
        elif k == ',':
            output += chr(st.pop(-1))
        elif k == 'p':
            a = st.pop(-1)
            b = st.pop(-1)
            v[a][b] = chr(st.pop(-1))
        elif k == 'g':
            a = st.pop(-1)
            b = st.pop(-1)
            st.append(ord(v[a][b]))
        elif k == '@':
            break

        y += dd[di][0]
        x += dd[di][1]

    return output
