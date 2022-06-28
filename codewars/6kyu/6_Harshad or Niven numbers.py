class Harshad:
    @staticmethod
    def is_valid(n):
        x = sum(int(x) for x in str(n))
        return n % x == 0

    @staticmethod
    def get_next(n):
        while True:
            n += 1
            if Harshad.is_valid(n):
                return n

    @staticmethod
    def get_series(count, s=0):
        r = []
        while len(r) < count:
            s += 1
            if Harshad.is_valid(s):
                r.append(s)
        return r