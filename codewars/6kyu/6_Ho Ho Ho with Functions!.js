function ho(x) {
    x = (x || '').replace('!', '')
    return x + (x ? ' ' : '') + 'Ho!'
}