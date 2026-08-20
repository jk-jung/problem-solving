def introverted_seat(s):
    if "0" not in s:
        return None
    if s.startswith("0 "):
        return "1" + s[1:]
    if " 0 " in s:
        return s.replace(" 0 ", " 1 ", 1)
    if s.endswith(" 0"):
        return s[:-1] + "1"

    for i in range(len(s)):
        if s[i] != "0":
            continue
        cnt = 0
        if i > 0 and s[i - 1] != " ":
            cnt += 1
        if i + 1 < len(s) and s[i + 1] != " ":
            cnt += 1
        if cnt != 2:
            return s[:i] + "1" + s[i + 1 :]
    return None
