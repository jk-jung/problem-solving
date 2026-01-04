def any_arrows(a):
    return any(not x.get("damaged") for x in a)
