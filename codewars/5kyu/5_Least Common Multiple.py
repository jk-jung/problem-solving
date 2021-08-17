def gcd(a, b): return a if not b else gcd(b, a % b)

def lcm(*v):
    r = 1
    for x in v:
        if x == 0: return  0;
        r = (r * x) // gcd(r, x)
    return r
  