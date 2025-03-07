function sortCards(array){
    let t = ['A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K']
    return array.sort((x, y) => t.indexOf(String(x)) - t.indexOf(String(y)))
}