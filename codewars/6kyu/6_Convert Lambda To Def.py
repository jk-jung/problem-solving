import re
def convert_lambda_to_def(s):
    t = re.match(r'(\w*) = (lambda) (\w*):(.*)', s)
    g = t.groups()
    return f'def {g[0]}({g[2]}):\n    return{g[3]}'
