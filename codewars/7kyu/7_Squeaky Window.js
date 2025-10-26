function sliding(a, k) {
  let r = [];
  for (let i = 0; i <= a.length - k; i++) {
    r.push(Math.max(...a.slice(i, i + k)));
  }
  return r;
}
