def tongues(code):
    a = 'a' 'i' 'y' 'e' 'o' 'u'
    b = 'b' 'k' 'x' 'z' 'n' 'h' 'd' 'c' 'w' 'g' 'p' 'v' 'j' 'q' 't' 's' 'r' 'l' 'm' 'f'
    A = a.upper()
    B = b.upper()
    r = ''
    for x in code:
        if x in a: r += a[a.index(x) - 3]
        elif x in A: r += A[A.index(x) - 3]
        elif x in b: r += b[b.index(x) - 10]
        elif x in B: r += B[B.index(x) - 10]
        else: r += x
    return r