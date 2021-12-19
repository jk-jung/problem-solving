N = 1000000
ck = [0 for _ in range(N)]
r = [[0, 0, 0] for _ in range(N)]

for i in range(2, N):
    if ck[i]: continue
    for j in range(i+i, N, i):
        ck[j] = 1

for i in range(13, N):
    r[i] = r[i-1][:]

    if ck[i]: continue
    j = int(str(i)[::-1])

    if i != j and ck[j] == 0:
        r[i][0] += 1
        r[i][1] = i
        r[i][2] += i

def find_emirp(n):
    return r[n]