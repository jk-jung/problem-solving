def initialize_names(n):
    n = n.split(' ')
    if len(n) <= 2:
        return ' '.join(n)
    return n[0] + ' ' + ' '.join(f"{x[0]}." for x in n[1:-1]) + " " + n[-1]
