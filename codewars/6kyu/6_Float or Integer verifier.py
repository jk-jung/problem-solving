def i_or_f(x):
    try:
        int(x)
        return True
    except:
        pass

    try:
        float(x)
        return True
    except:
        pass

    return False
