def scoobydoo(k, v):
    k = list(k.lower())
    for i in range(1, len(k), 2):
        x = k[i]
        k[i] = chr((ord(x) + 5 - ord('a')) % 26 + ord('a'))
    k = k[::-1]
    k = ''.join(k[5:] + k[:5])
    for x in v:
        if x.replace(' ', '').lower() == k:
            return x
        