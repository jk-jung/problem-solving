def freq_seq(s, sep):
    return sep.join(str(s.count(x)) for x in s)
