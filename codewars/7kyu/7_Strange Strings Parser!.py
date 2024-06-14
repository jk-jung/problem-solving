def word_splitter(s):
    for x in s:
        if not x.isalnum() and x != '-' and x != '.':
            s = s.replace(x, ' ')
    return s.split(' ')
