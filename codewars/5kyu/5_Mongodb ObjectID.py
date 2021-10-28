from datetime import datetime

CH = '0123456789abcdefg'
class Mongo(object):

    @classmethod
    def is_valid(cls, s):
        if type(s) != str: return False
        if len(s) != 24: return False
        if any(x not in CH for x in s): return False

        return True

    @classmethod
    def get_timestamp(cls, s):
        if not Mongo.is_valid(s): return False
        return datetime.fromtimestamp(int(s[:8], 16))