r = 0
class Class:

    @staticmethod
    def get_number():
        global r
        r *= 2
        if r == 0: r =1
        return r
    