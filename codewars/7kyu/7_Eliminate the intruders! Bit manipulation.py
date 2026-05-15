def eliminate_unset_bits(number):
    return (1 << number.count("1")) - 1