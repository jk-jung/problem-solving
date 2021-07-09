def make_readable(s):
    return '%02d:%02d:%02d' % (s // 3600, s % 3600 // 60, s % 3600 % 60)