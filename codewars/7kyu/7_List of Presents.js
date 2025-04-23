function howManyGifts(maxBudget, gifts){
    gifts.sort((a, b) => a - b)
    let r = 0
    for(let x of gifts){
        if(x <= maxBudget){
            r ++
            maxBudget -= x
        }
    }
    return r
}