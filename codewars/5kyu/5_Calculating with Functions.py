def plus(x): return lambda y: y + x
def minus(x): return lambda y: y - x
def times(x): return lambda y: y * x
def divided_by(x): return lambda y: y // x

def zero(func=times(1)): return func(0)
def one(func=times(1)): return func(1)
def two(func=times(1)): return func(2)
def three(func=times(1)): return func(3)
def four(func=times(1)): return func(4)
def five(func=times(1)): return func(5)
def six(func=times(1)): return func(6)
def seven(func=times(1)): return func(7)
def eight(func=times(1)): return func(8)
def nine(func=times(1)): return func(9)
