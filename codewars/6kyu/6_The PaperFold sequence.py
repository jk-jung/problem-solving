x = [1]
for i in range(20):
    x = x + [1] + [y^1 for y in x][::-1]

def paper_fold():
    for y in x:yield y
