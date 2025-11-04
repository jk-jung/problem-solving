from preloaded import Animal


class Cat(Animal):
    def __init__(self, n):
        self.n = n

    def speak(self):
        return f"{self.n} meows."
