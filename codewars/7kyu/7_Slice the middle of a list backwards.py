def reverse_middle(v):
    n, m = len(v) // 2, len(v)
    return v[n-1:n+2][::-1] if m % 2 else v[n-1:n+1][::-1]