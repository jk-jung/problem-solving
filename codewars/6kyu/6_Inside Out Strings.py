def inside_out(st):
    def rev(x): return ''.join(reversed(x))
    def f(x):
        n, m = len(x), len(x) // 2
        if n % 2:
            return rev(x[:m]) + x[m] + rev(x[m+1:])
        return rev(x[:m]) + rev(x[m:])
    return ' '.join(f(x) for x in st.split(' '))
