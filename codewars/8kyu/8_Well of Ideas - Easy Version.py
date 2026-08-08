def well(x):
    if x.count("good") == 0:
        return "Fail!"
    if x.count("good") > 2:
        return "I smell a series!"
    return "Publish!"
