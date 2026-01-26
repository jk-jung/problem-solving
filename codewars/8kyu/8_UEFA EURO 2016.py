def uefa_euro_2016(a, b):
    def f():
        if b[0] == b[1]:
            return "teams played draw."
        return f"{a[0] if b[0] > b[1] else a[1]} won!"

    return f"At match {a[0]} - {a[1]}, " + f()
