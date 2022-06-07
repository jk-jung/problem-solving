t = {
    'zero': 0,
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9,
}


def average_string(s):
    try:
        v = [t.get(x) for x in s.split(' ')]
        return {v: k for k, v in t.items()}[sum(v) // len(v)]
    except:
        return 'n/a'
