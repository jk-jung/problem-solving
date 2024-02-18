def name_that_number(x):
    ones = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
            "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
            "seventeen", "eighteen", "nineteen"]
    tens = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

    if x < 20:
        return ones[x]
    else:
        tens_place = x // 10
        ones_place = x % 10

        name = tens[tens_place]
        if ones_place > 0:
            name += " " + ones[ones_place]

        return name
