def max_tri_sum(numbers):
    return sum(sorted(set(numbers))[-3:])
