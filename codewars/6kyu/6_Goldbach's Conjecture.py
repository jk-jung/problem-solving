m = 1000000
a = [0 for _ in range(m)]
a[0] = a[1] = 1
for i in range(2, m):
    if not a[i]:
        for j in range(i + i, m, i):a[j] = 1

def check_goldbach(number):
    if number % 2: return []
    for i in range(2, number):
        if a[i] + a[number - i] == 0:
            return [i, number - i]
    return []
