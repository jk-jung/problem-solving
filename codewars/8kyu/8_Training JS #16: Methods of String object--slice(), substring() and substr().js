function cutIt(a) {
  m = Math.min(...a.map((x) => x.length));
  return a.map((x) => x.slice(0, m));
}
