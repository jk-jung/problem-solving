function numberOfFolds(n) {
  let i = 1,
    r = 0;
  while (i < n) {
    i *= 2;
    r++;
  }
  return r;
}
