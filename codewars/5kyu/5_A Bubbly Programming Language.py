def start(f):
    st = []
    return f(st)


def end(st):
    return st[-1]


def push(st):
    def _push(x):
        st.append(x)
        return lambda f: f(st)

    return _push


def add(st):
    st.append(st.pop() + st.pop())
    return lambda f: f(st)


def sub(st):
    st.append(st.pop() - st.pop())
    return lambda f: f(st)


def mul(st):
    st.append(st.pop() * st.pop())
    return lambda f: f(st)


def div(st):
    st.append(st.pop() // st.pop())
    return lambda f: f(st)
