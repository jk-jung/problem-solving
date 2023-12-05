def closed_brackets(s):
    st, c = [], 0
    for x in s:
        if x == '(': st.append('(')
        elif x == ')':
            if not st: return False
            ok = False
            for i in range(len(st) - 1, -1, -1):
                if st[i] == '(':
                    st.pop(i)
                    ok = True
                    break
            if not ok:
                st.pop()
        elif x == 'J':
            st.append('J')
    while len(st):
        while len(st) and st[-1] == 'J':
            c += 1
            st.pop()
        if len(st):
            if c == 0:
                print('1')
                return False
            c -= 1
            st.pop()
    return True
