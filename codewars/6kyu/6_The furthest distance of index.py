def furthest_distance(v, k):
    r = -1
    for i in range(len(v)):
        for j in range(len(v)):
            if abs(v[i] - v[j]) >= k:
                r = max(r, abs(i - j))
    return r
