n = 10000001
p = [0 for i in range(n)]
r = []
def good(x):
    while x:
        if x % 10 not in (2, 3, 5, 7): return False
        x //= 10
    return True

for i in range(2, n):
    if p[i]: continue
    if good(i): r.append(i)
    for j in range(i + i, n, i): p[j] = 1

def get_total_primes(a, b):
    return len([x for x in r if a <= x < b])
