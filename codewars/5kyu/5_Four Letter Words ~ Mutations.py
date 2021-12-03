def mutations(alice, bob, word, st):
    used = {word}
    def f(ss, x):
        for y in ss:
            if y in used: continue
            cnt = sum(1 for i in range(4) if x[i] != y[i])
            if cnt == 1: return y
        return None

    alice = [x for x in alice if len(set(x)) == 4]
    bob = [x for x in bob if len(set(x)) == 4]
    v = [alice, bob]
    if not f(v[0], word) and not f(v[1], word): return -1

    while True:
        word = f(v[st], word)
        st ^= 1
        if word is None: return st
        used.add(word)

    return st ^ 1
