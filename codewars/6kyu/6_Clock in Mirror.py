def what_is_the_time(t):
    h1, m1 = map(int, t.split(':'))

    h2 = 12 - h1 - (1 if m1 > 0 else 0)
    if h2 <= 0: h2 += 12
    m2 = (360 - m1 * 6) % 360 // 6

    return '%02d:%02d' %(h2, m2)
