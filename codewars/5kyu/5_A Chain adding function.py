class add(int):
    def __call__(self, x):
        return add(self + x)
