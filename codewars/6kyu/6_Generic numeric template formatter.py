def numeric_formatter(s : str, v : str = '1234567890') -> str:
    v = v * len(s)
    s = list(s)
    for i in range(len(s)):
        if s[i].isalpha():
            s[i] = v[0]
            v = v[1:]
    return ''.join(s)
