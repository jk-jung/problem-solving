from collections import Counter

def count_and_print_graph(s, m):
    c = Counter([x for x in s.lower() if x.isalpha()])
    c = sorted(c.items(), key=lambda x: (-x[1], x[0]))
    return '\n'.join(f'{k}:' + '#' * int(v * m / c[0][1]) for k, v in c)
