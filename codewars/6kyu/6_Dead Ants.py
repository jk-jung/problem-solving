def dead_ant_count (ants):
    s = ants.replace('ant', '')
    return max(s.count('a'), s.count('n'), s.count('t'))
