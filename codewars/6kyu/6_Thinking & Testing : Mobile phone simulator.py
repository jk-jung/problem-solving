class Phone:
    def __init__(self):
        self.state = -1
        self.ring = ''
        self.screen = ''
        self.microphone = ''

    def incomingcall(self, n):
        self.t = {x['number']: x for x in contacts}
        self.n = n
        self.state = self.t[n] if n in self.t else -2

        if self.state == -2:
            self.ring = 'Di Da Di'
            self.screen = f"Call: stranger\nNumber: {n}"
        else:
            self.ring = self.state['ring']
            self.screen = f"Call: {self.state['name']}\nNumber: {n}"


    def connect(self):
        self.ring = ''
        self.screen = ''
        if self.state == -2:
            self.microphone = f"Hello, who is speaking, please?"
        else:
            self.microphone = f"Hello, {self.state['name']}!"

    def hangup(self):
        self.ring = ''
        self.screen = ''
        self.microphone = ''
