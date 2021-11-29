def is_balanced(source, caps):
    st = [-1]
    for x in source:
        i = caps.find(x)
        if i == -1: continue
        elif caps[i - i % 2] == caps[i - i % 2 + 1]:
            if st[-1] == i: st.pop()
            else: st.append(i)
        elif i % 2:
            if st[-1] != i - 1:return False
            st.pop()
        else:
            st.append(i)
    return len(st) == 1