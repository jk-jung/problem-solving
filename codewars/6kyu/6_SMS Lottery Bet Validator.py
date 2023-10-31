def validate_bet(g, t):
    try:
        t = sorted(map(int, t.replace(',', ' ').split()))
        if len(t) != g[0]: return None
        if len(set(t)) != g[0]: return None
        if any(not(1 <= x <= g[1]) for x in t): return None
        return t
    except:
        return None
    