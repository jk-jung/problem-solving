function pickIt(arr) {
  let odd = [],
    even = [];
  for (let i of arr) {
    if (i % 2) odd.push(i);
    else even.push(i);
  }

  return [odd, even];
}
