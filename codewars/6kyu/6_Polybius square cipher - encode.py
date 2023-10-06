def polybius(t):
    def f(x):
        if x == ' ': return x
        n = ord(x) - ord('A')
        if x <= 'I': return f"{n // 5 + 1}{n % 5 + 1}"
        else:
            n -= 1
            return f"{n // 5 + 1}{n % 5 + 1}"
    return ''.join(f(x) for x in t)
