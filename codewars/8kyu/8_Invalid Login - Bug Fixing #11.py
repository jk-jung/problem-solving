def validate(a, b):
    if "||" in b or "//" in b:
        return "Wrong username or password!"
    return Database().login(a, b)
