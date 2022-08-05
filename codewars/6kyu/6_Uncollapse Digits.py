import re
def uncollapse(digits):
    return ' '.join(x for x in re.split('(zero|one|two|three|four|five|six|seven|eight|nine)', digits) if x)
