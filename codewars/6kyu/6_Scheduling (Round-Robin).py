def roundRobin(jobs, slice, index):
    i, r = 0, 0
    while jobs[index]:
        t = min(jobs[i], slice)
        jobs[i] -= t
        r += t
        i = (i + 1) % len(jobs)
    return r
