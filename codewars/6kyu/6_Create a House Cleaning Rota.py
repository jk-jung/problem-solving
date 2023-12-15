from random import sample

def rota(v):
    if len(v) >= 7: return sample(v, 7)
    return [sample(v, 1)[0] for _ in range(7)]