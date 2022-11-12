def words_to_hex(words):
    def f(x):
        r = '#'
        for i in range(min(3, len(x))):
            r += hex(ord(x[i]))[2:]
        return (r + '0' * 10)[:7]
    return [f(x) for x in words.split(' ') if x]
