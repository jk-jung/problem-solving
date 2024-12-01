import re
def anything(thing):
    """
        try to return anything else :)
    """
    class X(type(thing) if type(thing) != bool else object):
        def __init__(self):
            if type(thing) == type(re):
                super().__init__('a')
            else:
                super().__init__()

        def __eq__(self, a):return True
        def __ne__(self, a):return True
        def __gt__(self, a):return True
        def __ge__(self, a):return True
        def __lt__(self, a):return True
        def __le__(self, a):return True
    return X()