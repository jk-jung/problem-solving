def monkeys():
    t = """%s little monkeys jumping on the bed,
One fell off and bumped his head.
Mother called the doctor and the doctor said:
No more monkeys jumping on the bed!
"""
    return '\n'.join(t % x for x in ['Five', 'Four', 'Three', 'Two']) + """\nOne little monkey jumping on the bed,
He fell off and bumped his head.
Mother called the doctor and the doctor said:
Put those monkeys right to bed!"""