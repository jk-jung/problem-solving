spoken    = lambda s: s.title() + '.'
shouted   = lambda s: s.upper() + '!'
whispered = lambda s: s.lower() + '.'

greet = lambda f, s: f(s)