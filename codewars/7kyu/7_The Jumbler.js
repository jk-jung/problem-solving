function jumbler(a) {
    let r = 0
    while(a[0]){
      let idx = a[0]
      let b = [a[idx]]
      a.forEach((x, i) => {
        if(i !== idx)b.push(x)
      })
      r ++;
      a = b
    }
  
    return r
  }