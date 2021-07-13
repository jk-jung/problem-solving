class Machine:
    def __init__(self):
        self.bad = {}
        self.actions = ACTIONS()
        self.last = None

    def command(self, cmd, num):
        for i in range(len(self.actions)):
            if (cmd, i) in self.bad: continue
            self.last = (cmd, i)
            return self.actions[i](num)

    def response(self, res):
        if not res:
            self.bad[self.last] = 1
