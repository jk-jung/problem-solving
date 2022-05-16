from itertools import groupby

def run_length_encoding(s):
    return [[len(list(x[1])), x[0]] for x in groupby(s)]