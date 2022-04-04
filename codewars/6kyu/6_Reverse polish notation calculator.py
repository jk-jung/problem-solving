def calc(s):
    if not s:return 0
    st = []
    for x in s.split(' '):
        if x in '+*-/':
            a = st.pop()
            b = st.pop()
            st.append(eval(f'{b} {x} {a}'))
        else: st.append(eval(x))
    return st[-1]