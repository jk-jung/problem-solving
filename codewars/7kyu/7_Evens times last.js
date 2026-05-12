function evenLast(a) {
  let r = 0;
  for (let i = 0; i < a.length; i += 2) r += a[i];
  return r * a[a.length - 1] || 0;
}
