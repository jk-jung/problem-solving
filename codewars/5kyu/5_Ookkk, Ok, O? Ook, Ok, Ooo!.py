def okkOokOo(s):
    s = s.replace('O', '0').replace('o', '0').replace('k', '1')
    s = s.replace(',' ,'').replace(' ', '').replace('!', '')
    return ''.join(chr(int(x, 2)) for x in s.split('?'))
