def shifter(y):
    return sum([all(x in "HINOSXZMW" for x in s) for s in set(y.split())])
