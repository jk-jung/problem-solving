def rps(a, b):
    if a == b:
        return "Draw!"
    m = {
        "sp": "1",
        "sr": "2",
        "ps": "2",
        "pr": "1",
        "rs": "1",
        "rp": "2",
    }
    return f"Player {m[a[0] + b[0]]} won!"
