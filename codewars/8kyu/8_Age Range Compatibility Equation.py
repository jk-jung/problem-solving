def dating_range(a):
    if a > 14:
        return f"{a//2+7}-{2*(a-7)}"
    return  f"{int(a-.1*a)}-{int(a+.1*a)}"
