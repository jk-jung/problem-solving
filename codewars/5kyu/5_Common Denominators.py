def gcd(a, b): return a if not b else gcd(b, a % b)
def lcm(a, b): return a * b // gcd(a, b)
def convert_fracts(lst):
    r = 1
    for x in lst: r = lcm(r, x[1])
    return [
        [x[0] * r // x[1], r]
        for x in lst
    ]
