from time import time, sleep
def increment_loop(n):
    if n == 0:return 0
    i=0
    s = time()
    while True:
        i+=1
        if time() - s >= n:break
    return i
