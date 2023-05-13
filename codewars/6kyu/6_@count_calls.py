def count_calls(func):
    class C:
        def __init__(self):
            self.call_count = 0
            self.__name__ = func.__name__
            self.__doc__ = func.__doc__
        def __call__(self, *args, **kwargs):
            self.call_count += 1
            return func(*args, **kwargs)
    return C()
