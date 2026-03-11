def find_employees_role(k):
    m = {}
    for x in employees:
        a = x["first_name"]
        b = x["last_name"]
        m[b] = m[a + " " + b] = x["role"]
    return m.get(k, "Does not work here!")
