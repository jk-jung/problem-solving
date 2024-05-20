def reverse_slice(s):
    return [s[:len(s) - i][::-1] for i in range(len(s))]
