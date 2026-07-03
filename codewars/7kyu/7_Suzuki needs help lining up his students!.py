def lineup_students(s):
    if not s:
        return []
    return sorted(s.split(" "), key=lambda x: (len(x), x), reverse=True)
