function findMaxProduct(arr){
    let r = null;
    for(let i=1;i<=arr.length;i++){
        let t = 1;
        for(let j=i - 1;j<arr.length;j+=i)t *= arr[j];
        if(r == null || t > r)r = t;
    }
    return r;
}