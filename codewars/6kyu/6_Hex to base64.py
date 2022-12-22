import codecs
def hex_to_base64(s):
    return codecs.encode(codecs.decode(s, 'hex'), 'base64').decode().strip()
