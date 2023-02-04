import re
import math

def convert_recipe(recipe):
    def f(x):
        u = 15 if 'tbsp' in x[0] else 5
        if not x[1]: r = int(x[2]) * u
        else: r = math.ceil(int(x[1][:-1]) / int(x[2]) * u)
        return x[0] + f' ({r}g)'
    return re.sub(r'([0-9]*/)?([0-9]+) tb?sp', f, recipe)