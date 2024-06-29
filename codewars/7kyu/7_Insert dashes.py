import re
def insert_dash(num):
    def f(x):
        return x[1] + '-' + x[2]
    for i in range(100):
        num = re.sub(r'([13579])([13579])', f, str(num))
    return num


'''
import re

def insert_dash(num):
    #your code here
    return re.sub(r'([13579])(?=[13579])', r'\1-', str(num))
'''