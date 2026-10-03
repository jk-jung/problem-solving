from preloaded import Token

INT = "integer"
BOOL = "boolean"
STR = "string"
OP = "operator"
KW = "keyword"
ID = "identifier"
WS = "whitespace"

class Simplexer:

    def __init__(self, e):
        r = []
        i = 0
        n = len(e)
        while i < n:
            x = e[i]
            if x.isdigit():
                t = ""
                while i < n and e[i].isdigit():
                    t = t + e[i]
                    i += 1
                r.append(Token(t, INT))
            elif x in "+-*/%()=]":
                r.append(Token(x, OP))
                i += 1
            elif x == '"':
                i += 1
                t = ""
                while i < n and e[i] != '"':
                    t += e[i]
                    i += 1
                t = f'"{t}"'
                r.append(Token(t, STR))
                i += 1
            elif x in (' ', '\t', '\n'):
                t = ""
                while i < n and e[i] in (' ', '\t', '\n'):
                    t += e[i]
                    i += 1
                r.append(Token(t, WS))
            else:
                t = ""
                while i < n and (e[i].isalnum() or e[i] in '_$'):
                    t += e[i]
                    i += 1
                if t in ("true", "false"):
                    r.append(Token(t, BOOL))
                elif t in ("if", "else", "for", "while", "return", "func", "break"):
                    r.append(Token(t, KW))
                else:
                    r.append(Token(t, ID))
        self.r = r
        self.it = iter(self.r)
    
    def __iter__(self):
        return iter(self.r)
                
    def __next__(self):
        return next(self.it)
