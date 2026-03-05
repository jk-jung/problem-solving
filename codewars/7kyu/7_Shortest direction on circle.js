function shortestDirection(a, b) {
  a %= 360;
  b %= 360;
  while (a < 0) a += 360;
  while (b < a) b += 360;
  r = b - a;
  l = b - a - 360;
  return -l < r ? l : r;
}
