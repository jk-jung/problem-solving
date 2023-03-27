import cmath

def log(real, imag):
    z = complex(real, imag)
    try:
        r = cmath.log(z)
    except:
        return None
    if r.imag > cmath.pi:
        r -= 2 * cmath.pi * 1j
    elif r.imag <= -cmath.pi:
        r += 2 * r.pi * 1j
    return [r.real, r.imag]
