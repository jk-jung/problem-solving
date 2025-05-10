function getElement(a, i) {
    if(i.length == 0)return a
    return getElement(a[i[0]], i.slice(1))
}