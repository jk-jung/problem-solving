from collections import Counter
def simplify(s):

    while True:
        done = True
        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                c = Counter(s[i:j])
                x = c['<'] - c['>']
                y = c['^'] - c['v']
                if x == 0 and y == 0:
                    s = s[:i] + s[j:]
                    done = False
                    break
            if not done: break
        if done: break
    return s
