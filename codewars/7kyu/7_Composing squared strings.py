def compose(s1, s2):
    s1 = s1.split("\n")
    s2 = s2.split("\n")[::-1]
    return "\n".join(
        x[: i + 1] + y[: len(y) - i] for i, (x, y) in enumerate(zip(s1, s2))
    )
