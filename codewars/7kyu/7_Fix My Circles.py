def circle_mender(s: str) -> str:
    r = []
    for x in s.split("\n"):
        s, e = x.find("#"), x.rfind("#")
        if s == -1:
            r.append(x)
        else:
            r.append(" " * s + "#" * (e - s + 1) + " " * (len(x) - e - 1))
    return "\n".join(r)
