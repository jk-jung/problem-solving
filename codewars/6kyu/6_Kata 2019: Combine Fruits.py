from queue import PriorityQueue

def comb(f):
    q = PriorityQueue()
    [q.put(x) for x in f]
    r =0
    while True:
        a = q.get()
        if q.empty(): break
        b = q.get()
        r += a + b
        if q.empty(): break
        q.put(a + b)
    return r
