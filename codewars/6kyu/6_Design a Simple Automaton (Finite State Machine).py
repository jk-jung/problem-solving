class Automaton(object):

    def __init__(self):
        self.st = 1

    def read_commands(self, cmds):
        for x in cmds:
            x = int(x)
            if self.st == 3:
                self.st = 2
            elif self.st == 1:
                self.st += x
            else:
                self.st += (1 - x)
        return self.st == 2

my_automaton = Automaton()