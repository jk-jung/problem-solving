def best_match(g1, g2):
    return sorted([(abs(g1[i] - g2[i]), -g2[i], i) for i in range(len(g1))])[0][-1]