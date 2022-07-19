def hist(s):
    return '\r'.join(f"{k}  {s.count(k): <6}{'*' * s.count(k)}"for k in 'uwxz' if s.count(k))