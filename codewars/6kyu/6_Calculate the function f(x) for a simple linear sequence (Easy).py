def get_function(v):
    b = v[0]
    a = v[1] - v[0]

    for i in range(1, len(v)):
        if a * i + b != v[i]:
            return "Non-linear sequence"
    op = '+' if b > 0 else '-'
    if a == 0: op = ''
    if a == 0: return f"f(x) = {b}"
    if a < 0: return f"f(x) = {str(a) + 'x' if a != -1 else '-x'} {op} {abs(b) if b else ''}".strip(' +-')
    return f"f(x) = {str(a) + 'x' if a != 1 else 'x'} {op} {abs(b) if b else ''}".strip(' +-')