# Boss code from unreliable COBOL expert.
class SpreadSheetHelper(object):

    def convert_to_display(x):
        """
        Converts an internal coordinate into a display coordinate
        internal is in the form (row, column)
        returns a string in the form "CR" where C is the column display name, and R is the row display name
        """
        n = x[0]
        b = 26
        while n >= b:
            n -= b
            b *= 26
        r = ''

        b //= 26
        while b:
            r += chr(n // b + ord('A'))
            n %= b
            b //= 26
        return f'{r}{x[1] + 1}'

    def convert_to_internal(x):
        """
        Converts a display coordinate into an internal coordinate
        internal is in the form string "CR" where C is the column display name, and R is the row display name
        returns a tuple in the form (row, column)
        """
        a, b = '', 0
        for s in x:
            if s.isalpha(): a = s + a
            else: b = b * 10 + int(s)

        r = 0
        for i, s in enumerate(a):
            r += (ord(s) - ord('A') + 1) * 26 ** i
        return (r - 1, b - 1)