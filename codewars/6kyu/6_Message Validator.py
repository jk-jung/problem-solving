import re
def is_a_valid_message(message):
    r = [x for x in re.split('(\d+)', message) if x]
    if len(r) % 2:
        return False
    try:
        for i in range(0, len(r), 2):
            x, y = r[i:i + 2]
            if int(x) != len(y):
                return False
    except:
        return False
    return True