from collections import Counter
def string_evaluation(s, c):
    cnt = Counter(s)
    def f(x):
        def g(y): return y if y.isdigit() else cnt[y]
        return eval(f"{g(x[0])}{x[1:-1]}{g(x[-1])}")
    return [f(x) for x in c]
