from multiprocessing.pool import ThreadPool
def run(x):
    return x()
def task_master(v):
    s = 0
    with ThreadPool(processes=len(v)) as p:
        for x in  p.imap(run, v):
            s += x
        p.close()
        p.join()
    return s
