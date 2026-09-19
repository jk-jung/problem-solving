def digits(n):
    n = list(map(int, list(str(n))))
    r = []
    for i in range(len(n) - 1):
        for j in range(i + 1, len(n)):
            r.append(n[i] + n[j])
    return r


if __name__ == '__main__':
    assert digits(12345) == [3, 4, 5, 6, 5, 6, 7, 7, 8, 9]
    assert digits(12) == [3]
    assert digits(101) == [1, 2, 1]
    print('passed')
