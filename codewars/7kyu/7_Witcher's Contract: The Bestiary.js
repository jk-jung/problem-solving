function identifyMonster(a, b) {
  for (let k of Object.keys(b)) {
    x = b[k];
    if (a.every((y) => x.includes(y))) return k;
  }
  return "Unknown monster";
}
