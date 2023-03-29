def find_the_strongest_apes(v):
    def f(k):
        a = [x for x in v if x['type'] == k]
        if not a: return
        t = max(x['weight'] + x['height'] for x in a)
        a = [x for x in a if x['weight'] + x['height'] == t]
        return min(x['name'] for x in a)
    return {
        k: f(k)
        for k in ['Gorilla', 'Gibbon', 'Orangutan', 'Chimpanzee']
    }