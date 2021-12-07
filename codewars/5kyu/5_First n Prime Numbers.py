MAX = 1000000
prime = [0 for _ in range(MAX)]

p = []
for i in range(2, MAX):
    if prime[i]: continue
    else: p.append(i)
    for j in range(i + i, MAX, i): prime[j] = i

class Primes:
    def first(x):
        return p[:x]