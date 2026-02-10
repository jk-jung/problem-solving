function squaresOnly(a) {
  return a.filter(
    (x) => Math.round(Math.sqrt(x)) * Math.round(Math.sqrt(x)) === x,
  );
}
