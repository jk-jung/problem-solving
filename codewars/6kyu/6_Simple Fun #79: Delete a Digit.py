def delete_digit(n):
    n = str(n)
    return max(int(n[:i]+n[i+1:]) for i in range(len(n)))
