from itertools import groupby
def uniq(seq):
    return [x[0] for x in groupby(seq)]