def sort_emotions(v, o):
    a = {
        ':D': 0,
        ':)': 1,
        ':|': 2,
        ':(': 3,
        'T_T': 4,
    }
    return sorted(v, key=lambda x: a[x], reverse=not o)