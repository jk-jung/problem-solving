def sabb(s, a, b):
    t = len([x for x in s if x in 'sabbatical']) + a + b
    return  "Sabbatical! Boom!" if t > 22 else 'Back to your desk, boy.'