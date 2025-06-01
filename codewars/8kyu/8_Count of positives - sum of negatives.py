def count_positives_sum_negatives(arr):
    if not arr:
        return []

    return [sum([1 for x in arr if x > 0]), sum([x for x in arr if x < 0])]
