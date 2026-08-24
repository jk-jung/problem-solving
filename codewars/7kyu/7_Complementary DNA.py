def DNA_strand(d):
    return d.translate(str.maketrans("ATGC", "TACG"))
