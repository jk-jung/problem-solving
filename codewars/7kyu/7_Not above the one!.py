def binary_cleaner(s):
    return (
        [x for x in s if x < 2],
        [i for i, x in enumerate(s) if x >= 2]
    )
