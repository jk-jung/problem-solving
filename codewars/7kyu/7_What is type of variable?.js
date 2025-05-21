function type(value) {
    if(value === null)return 'null'
    try{
        value.push('1')
        return 'array'
    }catch(e){}
    try{
        value.getFullYear()
        return 'date'
    }catch(e){}
    return typeof(value)
}