d = [0 for _ in range(100001)]

for i in range(2, 100001):
    d[i] = d[i - 1] + 1
    if i % 2 == 0:
        d[i] = min(d[i], d[i // 2] + 1)

def shortest_steps_to_num(x):
    return d[x]ㅊ