def hexdump(data):
    r = ''
    for i in range(0, len(data), 16):
        v = ' '.join('%02x' % (x) for x in data[i:i + 16])
        s = ''.join(chr(x) if 31 < x < 127 else '.' for x in data[i:i + 16])
        v = (v + ' '* 100)[:49]
        r += '%08x: ' % (i) + v + s + '\n'
    return r.strip()

def dehex(text):
    r = b''
    for x in text.split('\n'):
        x = x.split(':')[1].split('  ')[0].strip().split(' ')
        for y in x:
            r += bytes([int(y, 16)])
    return r
