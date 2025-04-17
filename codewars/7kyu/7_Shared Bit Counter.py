def shared_bits(a, b):
    return (a & b).bit_count() > 1
