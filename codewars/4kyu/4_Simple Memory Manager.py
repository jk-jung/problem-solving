class MemoryManager:
    def __init__(self, memory):
        self.idx = 0
        self.vs = memory
        self.mem = [None for _ in range(len(memory))]

    def allocate(self, size):
        self.idx += 1
        cnt = 0
        for i in range(len(self.mem)):
            if not self.mem[i]: cnt += 1
            else: cnt = 0

            if cnt == size:
                for x in range(i - cnt + 1, i + 1):
                    self.mem[x] = self.idx
                return i - cnt + 1
        raise Exception('')

    def release(self, x):
        if x >= len(self.mem) or not self.mem[x]:
            raise Exception('')

        idx = self.mem[x]
        for i in range(len(self.mem)):
            if self.mem[i] == idx:
                self.mem[i] = None

    def read(self, x):
        if x >= len(self.mem) or not self.mem[x]:
            raise Exception('')
        return self.vs[x]

    def write(self, x, v):
        if x >= len(self.mem) or not self.mem[x]:
            raise Exception('')
        self.vs[x] = v
