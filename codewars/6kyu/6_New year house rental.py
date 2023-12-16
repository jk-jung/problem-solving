from collections import Counter

def calculate_cost_per_person(c: list[int], a: int) -> dict[int, int]:
    n = len(c)
    c = Counter(c)
    t = 0
    r = {}
    last = 0
    for k, v in sorted(c.items()):
        t += ((k - last) * a + n - 1) // n
        r[k] = t
        n -= v
        last = k

    return r