def prefill(n, v=None):
    try:
        return [v for _ in range(int(n))]
    except:
        raise TypeError(f'{n} is invalid')
