from calendar import monthrange

def schedule(emp, m, n):
    if len(emp) < n * 2: return None
    emp = emp * 50
    return [emp[i * n:i * n + n] for i in range(monthrange(int(m[2:]), int(m[:2]))[1])]
