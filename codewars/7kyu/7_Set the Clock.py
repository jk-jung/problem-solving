def set_clock(time, buttons):
    a, b = map(int, time.split(':'))
    a = (a + buttons.count('H')) % 24
    b = (b + buttons.count('M')) % 60
    if a == 0:a = 24
    return f"{a}:{b:02d}"