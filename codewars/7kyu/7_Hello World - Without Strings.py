def hello_world():
    a = [
        72,
        101,
        108,
        108,
        111,
        44,
        32,
        87,
        111,
        114,
        108,
        100,
        33,
    ]
    r = str()
    for x in a:
        r += chr(x)
    return r