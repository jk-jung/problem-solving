def validate_hello(a):
    t = ["hello", "ciao", "salut", "hallo", "hola", "ahoj", "czesc"]

    return any(x in a.lower() for x in t)
