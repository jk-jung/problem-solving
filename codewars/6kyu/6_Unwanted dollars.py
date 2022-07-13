def money_value(s):
    try:
        return float(s.replace('$', '').replace(' ', '') or 0)
    except:
        return 0
  