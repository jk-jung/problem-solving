magic_show = lambda s: sum([1 << i for i, x in enumerate(s.strip('|').split('|')) if 'Y' in x])