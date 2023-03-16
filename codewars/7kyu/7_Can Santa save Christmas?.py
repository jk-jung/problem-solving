def determine_time(arr):
    def f(x):
        v = list(map(int, x.split(':')))
        return v[0] * 3600 + v[1] * 60 + v[2]

    return sum(map(f, arr)) <= 3600 * 24
