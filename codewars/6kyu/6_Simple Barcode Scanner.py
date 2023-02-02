def barcode_scanner(s):
    p = {
        '0': '1110010',
        '1': '1100110',
        '2': '1101100',
        '3': '1000010',
        '4': '1011100',
        '5': '1001110',
        '6': '0101111',
        '7': '0111011',
        '8': '0110111',
        '9': '0001011',
    }
    a = s[3:45] + s[50:92]
    r = ''
    for i in range(0, len(a), 7):
        def f(x, y):
            return x == y or all(c != d for c, d in zip(x, y))
        r += [k for k, v in p.items() if f(v, a[i:i + 7])][0]
    return r
