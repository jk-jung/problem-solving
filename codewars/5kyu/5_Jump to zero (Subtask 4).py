N = 7 * 10**6
d = [0] * (N + 1)
ds = [0] * (N + 1)

for i in range(1, N + 1):
    ds[i] = ds[i // 10] + i % 10
    d[i] = d[i - ds[i]] + 1


def jump_to_zero(arr):
    return [d[x] for x in arr]
