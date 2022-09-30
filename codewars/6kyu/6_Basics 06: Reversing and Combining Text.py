def reverse_and_combine_text(t):
    while True:
        t = t.split(' ')
        if len(t) == 1: return t[0]
        if len(t) % 2: t.append('')
        t = ' '.join(''.join(reversed(t[i])) + ''.join(reversed(t[i + 1])) for i in range(0, len(t), 2))
