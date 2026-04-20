from typing import Sequence


def restore_code(t: Sequence[Sequence[str]]) -> str:
    r = []
    for x in t:
        if not x[1].isalpha():
            continue
        if not x[2].isalpha() and not x[2].lstrip("-").isdigit():
            continue
        if x[0] == "set":
            r.append(f"{x[1]}={x[2]}")
        elif x[0] == "add":
            r.append(f"{x[1]}+={x[2]}")
        elif x[0] == "sub":
            r.append(f"{x[1]}-={x[2]}")
    return "\n".join(r)
