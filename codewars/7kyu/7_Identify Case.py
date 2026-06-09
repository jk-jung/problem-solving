def case_id(s):
    if '_' in s and '-' in s:
        return "none"
    if '_' in s:
        if all(x.islower() and x.isalpha() for x in s.split('_')):
            return 'snake'
        return "none"
    if '-' in s:
        if all(x.islower() and x.isalpha() for x in s.split('-')):
            return 'kebab'
        return "none"
    if any(x.isupper() for x in s):
        return 'camel'
    return 'none'