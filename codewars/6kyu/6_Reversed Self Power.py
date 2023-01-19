t = [0, 1]
r = [0, 0, 1]
for i in range(2, 1001):
    for j in range(i):
        t[j] *= j
    t.append(i)
    r.append(len(str(sum(t))))

def min_length_num(num_dig, ord_max):
    for i, x in enumerate(r):
        if i <= ord_max and x == num_dig:
            return [True, i]
    return [False, -1]
