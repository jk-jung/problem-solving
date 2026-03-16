function belongsToArc(a, b, c) {
  a %= 360;
  b %= 360;
  c %= 360;

  if (a < 0) a += 360;
  if (b < 0) b += 360;
  if (c < 0) c += 360;

  if (a == c || b == c) return true;
  while (a != b) {
    a += 1;
    if (a >= 360) a -= 360;
    if (a == c) return true;
  }
  return false;
}
