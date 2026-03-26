function ballCollector(a) {
  return { weight: a.reduce((a, b) => a + (b == 58 ? 58 : 0), 0) };
}
