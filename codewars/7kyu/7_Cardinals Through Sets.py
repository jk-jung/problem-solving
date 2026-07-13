def zfc_definition(n):
    a = ["{}"]
    for x in range(n):
        a.append("{" + ",".join(a) + "}")
    return a[-1]
