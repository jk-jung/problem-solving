from collections import Counter

def get_winner(v):
    a, b = Counter(v).most_common(1)[0]
    return a if b > len(v) // 2 else None
