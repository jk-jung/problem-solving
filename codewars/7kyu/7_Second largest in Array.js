function secondLargest(a){
    try{
        if(typeof(a) !== typeof([]))return undefined
        a = a.map(x => parseFloat(x)).filter(x=>x !== NaN)
        return a.filter((x,i)=>a.indexOf(x) === i).sort((a, b) => b - a)[1]
    }
    catch{}
}