from functools import cache


@cache
def outcome(n, s, k):
    if n == 0:
        return k == 0
    return sum(outcome(n - 1, s, k - i) for i in range(1, min(k, s) + 1))
