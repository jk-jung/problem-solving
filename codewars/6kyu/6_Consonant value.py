import re
def solve(s):
    def v(s): return sum(ord(x) - ord('a') + 1for x in s)
    return max(v(x) for x in re.split('[aeiou]', s))