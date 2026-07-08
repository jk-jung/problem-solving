function generateMenu (t) {
    return t.map(x => `<a href="${x.url}">${x.text}</a>`).join('')
}