def house_of_cats(legs):
    return [i for i in range((legs + 1) // 2 + 1) if (legs - i * 2)% 4 == 0]
