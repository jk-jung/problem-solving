import os
from glob import glob
def create_file_dict():
    r = glob(os.path.join(os.getcwd(), '*'))
    def f(x):
        with open(x) as f:return f.read().split('\n')[0] + '\n'
    return  { os.path.basename(x): f(x) for x in r if not os.path.isdir(x)}
