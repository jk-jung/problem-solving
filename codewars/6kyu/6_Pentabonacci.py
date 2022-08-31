d = [0,1,1,2,4]
while len(d) < 100000:
    d.append(sum(d[-5:]))

def count_odd_pentaFib(n):
    return len({x for x in d[:n + 1] if x % 2})