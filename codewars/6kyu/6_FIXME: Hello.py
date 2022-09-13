class Dinglemouse(object):

    def __init__(self):
        self.name = None
        self.sex = None
        self.age = None
        self.order = []
        self.str = []

    def setAge(self, age):
        self.age = age
        if 'age' not in self.order:
            self.order.append('age')
            self.str.append('')
        self.str[self.order.index('age')] = f"I am {age}."
        return self

    def setSex(self, sex):
        self.sex = sex
        if 'sex' not in self.order:
            self.order.append('sex')
            self.str.append('')
        self.str[self.order.index('sex')] = f'I am {"male" if self.sex == "M" else "female"}.'
        return self

    def setName(self, name):
        if 'name' not in self.order:
            self.order.append('name')
            self.str.append('')
        self.str[self.order.index('name')] = f"My name is {name}."
        self.name = name
        return self

    def hello(self):
        return ("Hello. " + ' '.join(self.str)).strip()
