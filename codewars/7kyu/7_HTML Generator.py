class HTMLGen:
    def a(self, t):
        return f'<a>{t}</a>'

    def b(self, t):
        return f'<b>{t}</b>'

    def p(self, t):
        return f'<p>{t}</p>'

    def body(self, t):
        return f'<body>{t}</body>'

    def div(self, t):
        return f'<div>{t}</div>'

    def span(self, t):
        return f'<span>{t}</span>'

    def title(self, t):
        return f'<title>{t}</title>'

    def comment(self, t):
        return f'<!--{t}-->' 