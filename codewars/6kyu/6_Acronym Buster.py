t = {
    'KPI' :"key performance indicators",
    'EOD' :"the end of the day",
    'TBD' :"to be decided",
    'WAH' :"work at home",
    'IAM' :"in a meeting",
    'OOO' :"out of office",
    'NRN' :"no reply necessary",
    'CTA' :"call to action",
    'SWOT': "strengths, weaknesses, opportunities and threats",
}
def acronym_buster(s):
    r = []
    for x in s.split(' '):
        if len(x.strip('!.?')) >= 3 and all(y.isupper() or y in '!.?' for y in x):
            k = x[-1]
            x = x.strip('!.?')
            if x in t:
                r.append(t[x] + (k if k in '!.?' else ''))
            else:
                return f"{x} is an acronym. I do not like acronyms. Please remove them from your email."
        else: r.append(x)
    r = list(' '.join(r))
    flag = True
    for i in range(len(r)):
        if r[i] in '!.?': flag = True
        if r[i].isalpha() and flag:
            r[i] = r[i].upper()
            flag = False
    return ''.join(r)
