class List(object):
    def count_spec_digits(self, a, b):
        return [(x, sum(str(y).count(str(x)) for y in a)) for x in b]
