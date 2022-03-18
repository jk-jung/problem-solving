from itertools import groupby

r = [0 for _ in range(56)]
r[54] = 5691884

x = '1'
r[0] = 1
for i in range(54):
    y = ''
    for k, v in groupby(x):
        y += str(len(list(v))) + str(k)
    x = y
    r[i + 1] = sum(int(i) for i in x)


def look_and_say_and_sum(n):
    return r[n - 1]
