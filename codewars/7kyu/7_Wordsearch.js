function wordSearch(word, text){
    if(word.indexOf('.') !== -1) return false
    text = text.replace(',', ' ').replace('.', ' ')
    let i = text.indexOf(word)
    let j = i + word.length
    if(i === -1)return false
    if(i > 0 && text[i-1] !== ' ')return false
    if(j < text.length && text[j] !== ' ')return false
    return true
}
