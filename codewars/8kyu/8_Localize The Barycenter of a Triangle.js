function barTriang(a, b, c) {
  x = (a[0] + b[0] + c[0]) / 3;
  y = (a[1] + b[1] + c[1]) / 3;
  r = (k) => Math.round(k * 10000) / 10000;
  return [r(x), r(y)];
}
