def change(st):
    return ''.join('1' if x in st.lower() else '0' for x in 'abcdefghijklmnopqrstuvwxyz')