def words_to_object(s):
    s = s.split(' ')
    r = []
    if len(s) % 2 == 0:
        for i in range(0, len(s), 2):
            r.append(f"{{name : '{s[i]}', id : '{s[i+1]}'}}")
    return '[' + ', '.join(r) + ']'
