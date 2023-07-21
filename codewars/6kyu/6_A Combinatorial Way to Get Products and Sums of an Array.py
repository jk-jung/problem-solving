from itertools import combinations
from functools import reduce
def eval_prod_sum(a, b, c, d):
    if not all(isinstance(x, int) for x in a + [b, c, d]): return 'Error. Unexpected entries'
    if b <= 0 or c <= 0: return 'Error. Unexpected entries'
    if b > len(a): return "Error. Number of factors too high"
    a = [reduce(lambda x, y: x * y, v, 1) for v in combinations(a, b)]
    if c > len(a): return "Error. Number of addens too high"
    a = [sum(v) for v in combinations(a, c)]

    return [{f"Below than {d}" : sum(1 for x in a if x < d)},
            {f"Equals to {d}"  : sum(1 for x in a if x == d)},
            {f"Higher than {d}": sum(1 for x in a if x > d)}]