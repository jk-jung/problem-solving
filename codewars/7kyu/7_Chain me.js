function chain(n, f) {
  return f.reduce((x, y) => y(x), n);
}
