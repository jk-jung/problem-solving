def segment_cover(A, L):
    r = 0
    A.sort()
    while True:
        x = A.pop(0)
        while len(A) and x + L >= A[0]:A.pop(0)
        r += 1
        if not A:break
    return r