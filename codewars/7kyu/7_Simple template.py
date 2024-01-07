import re
def create_template(template):
    def f(**args):
        r = template
        for k, v in args.items():
            r = r.replace(f'{{{{{k}}}}}', v)
        r = re.sub(r'\{\{\w+\}\}', '', r)
        return r
    return f
