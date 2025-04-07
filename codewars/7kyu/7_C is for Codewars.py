def generate_C(s):
    r = ''
    for i in range(s):
        r +='C' * 5 * s + "\n"
    for i in range(3 * s):
        r += "C" * s + "\n"
    for i in range(s):
        r +='C' * 5 * s + "\n"
    return r.strip()