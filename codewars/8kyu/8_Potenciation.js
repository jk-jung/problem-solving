function power(x, y) {
  let r = 1;
  for (let i = 0; i < y; i++, r *= x);
  return r;
}
