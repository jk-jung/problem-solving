def list_animals(a):
    lst = ""
    for i in range(len(a)):
        lst += str(i + 1) + ". " + a[i] + "\n"
    return lst
