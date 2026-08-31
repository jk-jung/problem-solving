def printer_error(s):
    return str(len([x for x in s if 'n'<=x<='z']))+"/"+str(len(s))
