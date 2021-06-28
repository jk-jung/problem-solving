function countDistricts(city){
  let ck = {}
  Object.keys(city).forEach(x => ck[x] = x)

  let find = (x) => {
    if(ck[x] != x) ck[x] = find(ck[x])
    return ck[x]
  }

  let union = (x, y) => { ck[find(x)] = find(y) }

  Object.keys(city).forEach(x => {
    city[x].forEach(y => union(x, y))
  })

  let r = {}
  Object.keys(ck).forEach(x => r[find(x)] = 1)

  return Object.keys(r).length;
}