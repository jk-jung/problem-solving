from collections import Counter
def is_square(v):
    c = Counter()
    for i in range(len(v)):
        for j in range(i + 1, len(v)):
            dis = (v[i][0] - v[j][0]) ** 2 + (v[i][1] - v[j][1]) ** 2
            c[dis] += 1

    c = list(c.most_common())
    return len(c) == 2 and (c[0][1], c[1][1]) == (4, 2) and c[0][0] * 2 == c[1][0]
