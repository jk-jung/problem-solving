def create_array_of_tiers(n):
    return [str(n)[:i+1] for i in range(len(str(n)))]
