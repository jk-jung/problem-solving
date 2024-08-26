def number_lappings(my_speed,ghost_speed,time,round_length):
    diff = my_speed - ghost_speed
    if diff > 0:
        return int(time / (round_length / diff) - 1e-9)
    return 0
