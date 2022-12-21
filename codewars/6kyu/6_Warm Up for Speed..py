def sorted_comm_by_digs(a, b):
    def f(x):
        s = sum(map(int, str(x)))
        return -(s + sum(int(x) ** 2 for x in str(s))), x
    return sorted(set(a) & set(b), key=f)
