import os
def mkdirp(*v):
    os.makedirs(os.path.join(*v), exist_ok=True)
