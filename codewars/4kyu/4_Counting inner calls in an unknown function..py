import sys


def tracefunc(frame, event, arg, indent=[0]):
    global r
    if event == "call": r += 1
    return tracefunc


r = 0
sys.setprofile(tracefunc)


def count_calls(func, *args, **kwargs):
    global r
    r = 0
    rv = func(*args, **kwargs)
    return r - 1, rv
