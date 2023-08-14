class magicZ():
    def __init__(self):
        self.cards=[]
        self.cards+=[[1,4,6,9,12,14,17,19,22,25,27,30,33,35,38,40,43,46,48,51,53,56,59,61,64,67,69,72,74,77,80,82,85,88,90,93,95,98]]
        self.cards+=[[2,7,10,15,20,23,28,31,36,41,44,49,54,57,62,65,70,75,78,83,86,91,96,99]]
        self.cards+=[[3,4,11,12,16,17,24,25,32,33,37,38,45,46,50,51,58,59,66,67,71,72,79,80,87,88,92,93,100]]
        self.cards+=[[5,6,7,18,19,20,26,27,28,39,40,41,52,53,54,60,61,62,73,74,75,81,82,83,94,95,96]]
        self.cards+=[[8,9,10,11,12,29,30,31,32,33,42,43,44,45,46,63,64,65,66,67,84,85,86,87,88,97,98,99,100]]
        self.cards+=[[13,14,15,16,17,18,19,20,47,48,49,50,51,52,53,54,68,69,70,71,72,73,74,75]]
        self.cards+=[[21,22,23,24,25,26,27,28,29,30,31,32,33,76,77,78,79,80,81,82,83,84,85,86,87,88]]
        self.cards+=[[34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54]]
        self.cards+=[[55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88]]
        self.cards+=[[89,90,91,92,93,94,95,96,97,98,99,100]]

    def gueZZ(self,v=None):
        try:
            rr = 0
            for x in set(v):
                rr += self.cards[x][0]
            return rr
        except:
            return 0


    def get_magicZ_index(self, n):
        r = []
        for i, x in enumerate(self.cards):
            if n in x:r.append(i)
        return r
